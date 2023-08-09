#include "head_chef.h"


using std::placeholders::_1;
using namespace std::chrono_literals;

//Used to track when the program is stopped, and cease motor motion then
bool isRunning = true;

//Debugging variables, can be ignored
double tAz = 0.0;
double tAlt = 0.0;
int loopLen = 1;

//Catches signal interrupt allowing us to do some final shutdown commands
void signal_callback_handler(int signum) {
	isRunning = false;
	signal(SIGINT, SIG_DFL);
}


HeadChef::HeadChef() : Node("head_chef") {
	std::cout << "Starting head chef\n";
	//Define our initial motor positions to zero rather than random
	motorPs[0] = 0.0;
	motorPs[1] = 0.0;
	motorPs[2] = 0.0;
	motorPs[3] = 0.0;
	//Set our desired positions to the same
	desiredMotorPs[0] = 0.0;
	desiredMotorPs[1] = 0.0;
	desiredMotorPs[2] = 0.0;
	desiredMotorPs[3] = 0.0;
	//Don't command any velocity at start-up
	commVels[0] = 0.0;
	commVels[1] = 0.0;
	commVels[2] = 0.0;
	commVels[3] = 0.0;
	
	//Set PID values from config files
	pid1 = getFromFile("/home/seastar/steve_summer_seastar_ws/settings/pid1.cfg");
	pid2 = getFromFile("/home/seastar/steve_summer_seastar_ws/settings/pid2.cfg");
	pid3 = getFromFile("/home/seastar/steve_summer_seastar_ws/settings/pid3.cfg");
	
	//Load our scripts
	cs = ChefScript("/recipes/testScript.rcp");
	//Gives reference to this object so the script can call our functions.
	cs.hireChef(this);
	
	//For testing
	solarVecS.x = 1;
	solarVecS.y = DEG2RAD((tAz));
	solarVecS.z = DEG2RAD(tAlt);
	
	pid1.enableLog();
	//pid2.enableLog();
	
	//Setup subscriptions and publications 
	sub1_ = this->create_subscription<std_msgs::msg::String>("motors0", 10, std::bind(&HeadChef::firstPairListener, this, _1));
	sub2_ = this->create_subscription<std_msgs::msg::String>("motors1", 10, std::bind(&HeadChef::secondPairListener, this, _1));
	ephemSub_ = this->create_subscription<seastar_interfaces::msg::SkyEphemeris>("solar_ephemeris", 10, std::bind(&HeadChef::ephemUpdate, this, _1));
	roboEphemSub_ = this->create_subscription<seastar_interfaces::msg::SkyEphemeris>("robot_ephemeris", 10, std::bind(&HeadChef::roboEphemUpdate, this, _1));
	imuSub_ = this->create_subscription<geometry_msgs::msg::QuaternionStamped>("/filter/quaternion", 10, std::bind(&HeadChef::imuUpdate, this, _1));
	sunSub_ = this->create_subscription<std_msgs::msg::String>("/sunspot", 10, std::bind(&HeadChef::sunUpdate, this, _1));
	commPub_ = this->create_publisher<std_msgs::msg::String>("motor_commands", 10);
	joint_pub_ = this->create_publisher<sensor_msgs::msg::JointState>("joint_states", 10);
	client_ = this->create_client<seastar_interfaces::srv::PointMotors>("ik_solver");
	jacSub_ = this->create_subscription<std_msgs::msg::String>("/inv_jacobian", 10, std::bind(&HeadChef::jacUpdate, this, _1));
	homeSub_ = this->create_subscription<std_msgs::msg::Bool>("/is_homing", 10, std::bind(&HeadChef::homeUpdate, this, _1));
	
	//Wait for requested service to be available
	while (!client_->wait_for_service(1s)) {
		if (!rclcpp::ok()) {
			RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted waiting for service. Exiting.");
			return;
		}
	}
	
	//timer_ = this->create_wall_timer(20ms, std::bind(&HeadChef::orderMotors, this));
}

void HeadChef::homeUpdate(const std_msgs::msg::Bool& msg) {
	if (mode == Homing) {
		//printf("Got homing update\n");
		doneWithCommand = !msg.data;
		if (doneWithCommand) {
			mode = WaitForComm;	
		}
	}
}

//Listen for the first motor_state_manager to publish the positions of the roll and pitch motors
void HeadChef::firstPairListener(const std_msgs::msg::String& msg) {
	//std::cout << "Heard " << msg.data.c_str() << std::endl;
	double* state = trackingStates(msg.data);
	motorPs[0] = state[0];
	motorPs[1] = state[1];
	motorPs[2] = state[2];
	orderMotors();
	publishJointState();
}

//Listen for the second motor_state_manager to publish the stokes and plate positions
void HeadChef::secondPairListener(const std_msgs::msg::String& msg) {
	double* state = motorStates(msg.data);
	motorPs[2] = state[0];
	motorPs[3] = state[1];
	orderMotors();
	publishJointState();
}

//Listen for the ik_tools inverse jacobian, and if the mode is right, use it to follow the sun.
void HeadChef::jacUpdate(const std_msgs::msg::String& msg) {
	double* state = trackingStates(msg.data);
	if (mode == SunTracking || mode == SunTrackingTest) {
		commVels[0] = state[0];
		commVels[1] = state[1];
	}
	publishJointState();
	
}

//Listen for the ik_tools publication of where the robot thinks its pointing, for tracking the offset in the IMU
void HeadChef::roboEphemUpdate(const seastar_interfaces::msg::SkyEphemeris& msg) {
	double robotAz = msg.azimuth;
	double robotAlt = msg.elevation;
	
	double acAz = RAD2DEG(solarVecC.y);
	double acAlt = RAD2DEG(solarVecC.z);
	
	azOff = robotAz - acAz;
	altOff = robotAlt - acAlt;
	
	//printf("Azimuth offset: %f\nAltitude offset: %f\n", azOff, altOff);
	publishJointState();
}

//Get the solar ephemeris, and then rotate it by the IMU's rotation
void HeadChef::ephemUpdate(const seastar_interfaces::msg::SkyEphemeris& msg) {
	//std::cout << msg.elevation << ", " << msg.azimuth << std::endl;
	solarAz = msg.azimuth;
	solarAlt = msg.elevation;
	
	solarVecS.x = 1;
	solarVecS.y = DEG2RAD(solarAz);
	solarVecS.z = DEG2RAD(solarAlt);

	
	//solarVecS.y = DEG2RAD(180.0);
	//solarVecS.z = DEG2RAD(30.0);
	
	orderMotors();
	publishJointState();
}

//Get the location of the sun spot and store where on the camera it is
//Function probably not needed anymore and is computed in ik_tools but too lazy to remove all references to it
void HeadChef::sunUpdate(const std_msgs::msg::String& msg) {
	double* sunSpots = motorStates(msg.data.c_str());
	camX = (((camW / 2) - sunSpots[0]) / camW);
	camY = (((camH / 2) - sunSpots[1]) / camH);
}

void HeadChef::homeAll() {
	printf("Sending first homing message\n");
	auto message = std_msgs::msg::String();
	message.data = "0H";
	commPub_->publish(message);

	mode = Homing;
}

void HeadChef::findSun() {
	mode = SunSeeking;
}

void HeadChef::findTarg() {
	mode = TargSeeking;
}

void HeadChef::trackSunFor(double t) {
	start_ = std::chrono::high_resolution_clock::now();
	mode = SunTracking;
	targTime = t;
}

void HeadChef::findSunFor(double t) {
	start_ = std::chrono::high_resolution_clock::now();
	mode = SunSeekingTimer;
	targTime = t;
}

void HeadChef::findStayTarg(double t) {
	start_ = std::chrono::high_resolution_clock::now();
	mode = TargSeekingTimer;
	targTime = t;
}

//Here we communicate with the motor_state_manager, giving in the desired velocity commands from either the inverse jacobian or the PIDs
void HeadChef::orderMotors() {
	cook();
	if (isRunning) {
		for (int i = 0; i < 4; ++i) {
			while (desiredMotorPs[i] > 200000 || desiredMotorPs[i] < 0) {
				if (desiredMotorPs[i] > 200000) {
					desiredMotorPs[i] -= 200000;
				} else {
					desiredMotorPs[i] += 200000;
				}
			}
		}
		if (mode == SunSeeking || mode == SunSeekingTest || mode == SunSeekingTimer || mode == DrawCircleSun || mode == DrawCircleTarg || mode == DrawArcSun || mode == DrawArcTarg || mode == TargSeeking || mode == TargSeekingTimer) {
			pid1.setSetpoint(desiredMotorPs[0]);
			commVels[0] = pid1.update(motorPs[0]);
			pid2.setSetpoint(desiredMotorPs[1]);
			commVels[1] = pid2.update(motorPs[1]);
			pid3.setSetpoint(desiredMotorPs[2]);
			commVels[2] = pid3.update(motorPs[2]);
		}
		
		auto message = std_msgs::msg::String();
		
		message.data = "0 " + std::to_string(commVels[0]) + "," + std::to_string(commVels[1]) + "," + std::to_string(commVels[2]);
		commPub_->publish(message);
		
		message.data = "1 " + std::to_string(commVels[3]) + "," + std::to_string(0.0);
		commPub_->publish(message);
		
		if (mode == SunTracking || mode == SunTrackingTest) {
			//Need to do this since we update the velocity in another node, and if we interrupt it, we don't want it to continute at the last speed
			commVels[0] = 0.0;
			commVels[1] = 0.0;
			commVels[2] = 0.0;
		}
		
	} else {
		//Sends command to set velocities to zero
		auto message = std_msgs::msg::String();
		message.data = "0 0.0,0.0,0.0";
		commPub_->publish(message);
		
		pid1.closeLog();
		//pid2.closeLog();
		//Sends command to home the motors (for debugging convience)
		message.data = "0H";
		commPub_->publish(message);
		
		//Close the log file if we were testing
		if (openedLog) {
			logFile.close();
		}
		
		//Complete the keyboard interrupt we caught to do our shutdown
		std::raise(SIGINT);
	}
}

void HeadChef::checkSunTimer() {
	std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = end - start_ ;
	//std::cout << diff.count() << std::endl;
	if (diff.count() > targTime) {
		doneWithCommand = true;
		mode = WaitForComm;
		commVels[0] = 0.0;
		commVels[1] = 0.0;
		commVels[2] = 0.0;
	}
}

//Call the relevant commands depending on the current mode.
void HeadChef::cook() {
	//printf("Cook called\n");
	if (doneWithCommand) {
		printf("Running next command\n");
		doneWithCommand = false;
		cs.execNextLine();
	}
	
	//std::cout << mode << std::endl;
	
	switch (mode) {
		case SunSeeking:
			seekSun();
			break;
		case SunSeekingTimer:
			seekSun();
			checkSunTimer();
			break;
		case SunSeekingTest:
			seekSun();
			logSunData();
			break;
		case SunTracking:
			followSun();
			checkSunTimer();
			break;
		case SunTrackingTest:
			followSun();
			logSunData();
			break;
		case DrawCircleSun:
			seekLoopPos();
			break;
		case TargSeeking:
			seekSTarg();
			break;
		case TargSeekingTimer:
			seekSTarg();
			checkSunTimer();
			break;
		case DrawArcSun:
		case DrawArcTarg:
			seekArcPos();
			break;
		case WaitForComm:
			commVels[0] = 0.0;
			commVels[1] = 0.0;
			commVels[2] = 0.0;
		default:
			//What
			break;
	}
	
}

//Will draw circle around sun
void HeadChef::loopSun(double size) {
	printf("Drawing circle around sun of size %f\n", size);
	mode = DrawCircleSun;
	loopStep = 0;
	circRad = size;
}

void HeadChef::arcSun(double size) {
	printf("Drawing arc around sun of size %f from %f to %f\n", size, arcStart, arcEnd);
	loopStep = 0;
	circRad = size;
	mode = DrawArcSun;
	circRad = size;
}

void HeadChef::arcTarg(double size) {
	printf("Drawing arc around secondary target of size %f from %f to %f\n", size, arcStart, arcEnd);
	loopStep = 0;
	circRad = size;
	mode = DrawArcTarg;
	circRad = size;
}

void HeadChef::loopTarg(double size) {
	printf("Drawing circle around sun of size %f\n", size);
	mode = DrawCircleTarg;
	loopStep = 0;
	circRad = size;
}

void HeadChef::setSolarAzOff(double off) {
	commSolarAzOff = off;
	doneWithCommand = true;
	mode = WaitForComm;
}

void HeadChef::setSolarAltOff(double off) {
	commSolarAltOff = off;
	doneWithCommand = true;
}

void HeadChef::setSolarPolar(double pol) {
	solarPol = pol;
	doneWithCommand = true;
	mode = WaitForComm;
}

void HeadChef::setSTargAz(double az) {
	sTargAz = az;
	doneWithCommand = true;
	mode = WaitForComm;
}

void HeadChef::setSTargAlt(double alt) {
	sTargAlt = alt;
	doneWithCommand = true;
	mode = WaitForComm;
}

void HeadChef::setSTargPol(double pol) {
	sTargPol = pol;
	doneWithCommand = true;
	mode = WaitForComm;
}

void HeadChef::setArcStart(double start) {
	arcStart = start;
	doneWithCommand = true;
	mode = WaitForComm;
}
void HeadChef::setArcEnd(double end) {
	arcEnd = end;
	doneWithCommand = true;
	mode = WaitForComm;
}

//Logs data for debugging. 
void HeadChef::logSunData() {
	if (!openedLog) {
		uint64_t sec = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
		std::string fileName = "sunLog" + std::to_string(sec) + ".csv";
		logFile.open(fileName);
		logFile << "t, az, alt, rAz, rAlt, q1, q2, camX, camY, azOff, altOff\n";
		openedLog = true;
	} else {
		uint64_t sec = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
		logFile << sec << ", " << solarAz << ", " << solarAlt << ", " << (RAD2DEG(solarVecC.y)) << ", " << (RAD2DEG(solarVecC.z)) << ", " << encToAng(motorPs[0]) << ", " << encToAng(motorPs[1]) << ", " << camX << ", " << camY << ", " << azOff << ", " << altOff << "\n";  
	}
}

void HeadChef::seekArcPos() {
	double theta = solarVecC.y;
	double phi = solarVecC.z;
	
	if (mode == DrawArcTarg) {
		theta = sTargVecC.y;
		phi = sTargVecC.z;
	}
	
	//printf("Theta: %f\t\tphi: %f\n", RAD2DEG(theta), RAD2DEG(phi));
	
	double arcStep = (arcEnd - arcStart) / (double) loopMax;
	
	double cAng = (((double) loopStep / (double) loopMax) * arcStep) + DEG2RAD(arcStart);
	
	double tOff = DEG2RAD(circRad * cos(cAng));
	double pOff = DEG2RAD(circRad * sin(cAng));
	
	//printf("%f %f %f\n", cAng, tOff, pOff);
	
	auto request = std::make_shared<seastar_interfaces::srv::PointMotors::Request>();
	request->point.azimuth = (float) RAD2DEG((theta + tOff));
	request->point.altitude = (float) RAD2DEG((phi + pOff));
	request->point.polarization = 0.0f;
	request->input_state.q1 = (float) encToAng(motorPs[0]);
	request->input_state.q2 = (float) encToAng(motorPs[1]);
	request->input_state.q3 = (float) encToAng(motorPs[2]);
	//No good way to wait for it other than another function handler	
	auto result_future = client_->async_send_request(request, std::bind(&HeadChef::use_ik, this, std::placeholders::_1));	
	
}

void HeadChef::seekLoopPos() {
	double theta = solarVecC.y;
	double phi = solarVecC.z;
	
	if (mode == DrawCircleTarg) {
		theta = sTargVecC.y;
		phi = sTargVecC.z;
	}

	double cAng = (((double)loopStep / (double)loopMax)) * 2 * PI;
	
	double tOff = DEG2RAD(circRad * cos(cAng));
	double pOff = DEG2RAD(circRad * sin(cAng));
	
	//printf("%f %f %f\n", cAng, tOff, pOff);
	
	auto request = std::make_shared<seastar_interfaces::srv::PointMotors::Request>();
	request->point.azimuth = (float) RAD2DEG((theta + tOff));
	request->point.altitude = (float) RAD2DEG((phi + pOff));
	request->point.polarization = 0.0f;
	request->input_state.q1 = (float) encToAng(motorPs[0]);
	request->input_state.q2 = (float) encToAng(motorPs[1]);
	request->input_state.q3 = (float) encToAng(motorPs[2]);
	//No good way to wait for it other than another function handler	
	auto result_future = client_->async_send_request(request, std::bind(&HeadChef::use_ik, this, std::placeholders::_1));	
	
	
}

//Gets current values, packages them together, and sends request off to ik_solver
void HeadChef::seekSun() {
	double theta = solarVecC.y + DEG2RAD(commSolarAzOff);
	double phi = solarVecC.z + DEG2RAD(commSolarAltOff);
	
	if (theta <= 0) {
		theta += (DEG2RAD(360.0));
	}
	
	//std::cout << "Quat (x, y, z, w):\t" << imu.x << ", " << imu.y << ", "<< imu.z << ", "<< imu.w << std::endl;
	
	//std::cout<<"Rotated position:\t" << RAD2DEG(theta) << ", " << RAD2DEG(phi) << std::endl; 
	
	auto request = std::make_shared<seastar_interfaces::srv::PointMotors::Request>();
	request->point.azimuth = (float) RAD2DEG(theta);
	request->point.altitude = (float) RAD2DEG(phi);
	request->point.polarization = (float) RAD2DEG(solarPol);
	request->input_state.q1 = (float) encToAng(motorPs[0]);
	request->input_state.q2 = (float) encToAng(motorPs[1]);
	request->input_state.q3 = (float) encToAng(motorPs[2]);
	//No good way to wait for it other than another function handler	
	auto result_future = client_->async_send_request(request, std::bind(&HeadChef::use_ik, this, std::placeholders::_1));	
}

void HeadChef::seekSTarg() {
	double theta = sTargVecC.y;
	double phi = sTargVecC.z;
	
	if (theta <= 0) {
		theta += (DEG2RAD(360.0));
	}
	
	//std::cout << "Quat (x, y, z, w):\t" << imu.x << ", " << imu.y << ", "<< imu.z << ", "<< imu.w << std::endl;
	
	//std::cout<<"Rotated position:\t" << RAD2DEG(theta) << ", " << RAD2DEG(phi) << std::endl; 
	
	auto request = std::make_shared<seastar_interfaces::srv::PointMotors::Request>();
	request->point.azimuth = (float) RAD2DEG(theta);
	request->point.altitude = (float) RAD2DEG(phi);
	request->point.polarization = (float) RAD2DEG(sTargPol);
	request->input_state.q1 = (float) encToAng(motorPs[0]);
	request->input_state.q2 = (float) encToAng(motorPs[1]);
	request->input_state.q3 = (float) encToAng(motorPs[2]);
	//No good way to wait for it other than another function handler	
	auto result_future = client_->async_send_request(request, std::bind(&HeadChef::use_ik, this, std::placeholders::_1));	
}

//Once the IK has been solved, this catches the reply and sets the relevant commands. Also tracks percent error for fun and for knowing when a point has been reached.
void HeadChef::use_ik(rclcpp::Client<seastar_interfaces::srv::PointMotors>::SharedFuture future) {
	//printf("IK callback good\n");
	auto status = future.wait_for(1s);
	if (status == std::future_status::ready) {
		//RCLCPP_INFO(this->get_logger(), "Finally saw response");
		auto out = future.get()->command;
		//std::cout << out.q1 << ", " << out.q2 << ", " << out.q3 << std::endl;
		desiredMotorPs[0] = angToEnc(out.q1);
		desiredMotorPs[1] = angToEnc(out.q2);
		desiredMotorPs[2] = angToEnc(out.q3);
				
		double e1 = motorPs[0] - desiredMotorPs[0];
		double e2 = motorPs[1] - desiredMotorPs[1];
		
		double pe1 = (e1 / desiredMotorPs[0]) * 100;
		double pe2 = (e2 / desiredMotorPs[1]) * 100;
		
		//printf("Percent error 1: %f\nPercent error 2: %f\n", pe1, pe2);
		
		if (abs(pe1) < 0.5 && abs(pe2) < 0.5 && (mode == SunSeeking || mode == SunSeekingTest || mode == TargSeeking)) {
			//printf("At the sun. Switching to tracking\n");
			//printf("Spot reached. Moving to next.\n");
			//mode = DrawCircle;
			//mode = SunTrackingTest;
			doneWithCommand = true;
			mode = WaitForComm;
		}
		
		if ((mode == DrawCircleSun || mode == DrawCircleTarg || mode == DrawArcSun || mode == DrawArcTarg) && abs(pe1) < 1 && abs(pe2) < 1) {
			//printf("%d\n", loopStep);
			if (loopStep == loopMax) {
				doneWithCommand = true;
				mode = WaitForComm;
			} else {
				loopStep++;
			}
			
		}
	}
}

//Used to be used to follow the sun. Not really needed now, artifact I'm too lazy to delete
void HeadChef::followSun() {
}

//Publishes all the joint states in case we want to view what's happening with rviz2
void HeadChef::publishJointState() {
	joint_state_.header.stamp = now();
	joint_state_.name = {"upright1_to_roll_joint", "roll_to_pitch_joint", "pitch_to_stokes_joint"};
	joint_state_.position = {DEG2RAD(encToAng(motorPs[0])), DEG2RAD(encToAng(motorPs[1])), DEG2RAD(encToAng(motorPs[2]))};
	joint_pub_->publish(joint_state_);	
	
}

//Old function to convert roll motor encoded positions to degrees. Not really needed.
double HeadChef::encodeToPos1(double enc) {
	return (-0.0017514923 * enc) - 205.959516;
}
//Old function to convert pitch motor encoded positions to degrees. Not really needed.
double HeadChef::encodeToPos2(double enc) {
	return (-0.00175149328 * enc) + 183.040592;
}
//Old function to convert stokes motor encoded positions to degrees. Not really needed.
double HeadChef::encodeToPos3(double enc) {
	return (-0.00178782968 * enc) - 1.89632768;
}	

//Currently used function to convert encoder position to degrees
double HeadChef::encToAng(double enc) {
	return fmod((0.0018 * enc), 360.0);
}

//Currently used function to convert degrees to encoder positions
double HeadChef::angToEnc(double ang) {
	return fmod((555.555555 * ang), 200000.0);
}

//Listens for the orientation of the IMU, and then takes the inverse of the quaternion, to undo any rotation it sees
void HeadChef::imuUpdate(const geometry_msgs::msg::QuaternionStamped msg) {
	double x = -msg.quaternion.x;
	double y = -msg.quaternion.y;
	double z = -msg.quaternion.z;
	double w = msg.quaternion.w;
	
	imu.x = x;
	imu.y = y;
	imu.z = z;
	imu.w = w;
	
	//solarVecS.x = 1;
	//solarVecS.y = DEG2RAD(solarAz);
	//solarVecS.z = DEG2RAD(solarAlt);
	
	solarVecC = rotateSpher(solarVecS, imu);
	
	sTargVecS.x = 1;
	sTargVecS.y = DEG2RAD(sTargAz);
	sTargVecS.z = DEG2RAD(sTargAlt);
	
	//printf("%f %f\n", sTargAz, sTargAlt);
	
	
	sTargVecC = rotateSpher(sTargVecS, imu);
	
	//imu = fixQuat(imu);
	
	//imu = multQuat(imuTransform, imu);
	
	//printf("%f %f %f %f\n", x, y, z, w);
}

//Start and run our node
int main(int argc, char ** argv) {
	rclcpp::init(argc, argv);
	signal(SIGINT, signal_callback_handler);
	rclcpp::spin(std::make_shared<HeadChef>());
	rclcpp::shutdown();
	return 0;
}
