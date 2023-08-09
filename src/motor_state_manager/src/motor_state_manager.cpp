#include "helper.h"
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/bool.hpp"
#include "ament_index_cpp/get_package_prefix.hpp"

using namespace std::chrono_literals;
using std::placeholders::_1;

//Watch for keyboard interrupt, and if it hits, this will let us run a few more commands before stopping
bool isRunning = true;
void signal_callback_handler(int signum) {
	isRunning = false;
	signal(SIGINT, SIG_DFL);
	//printf("Node has been killed, but to kill ROS you need to Ctrl-C one more time\n");
}


class MSM : public rclcpp::Node {
public:
	MSM() : Node("motor_state_manager") {

		sub_ = this->create_subscription<std_msgs::msg::String>("motor_commands", 10, std::bind(&MSM::commands, this, _1));
		RCLCPP_INFO(this->get_logger(), "Searching for COM ports");
		ports = getAvailPorts();
		//Select the first open port. If this is the second pair of motors, it should see the first as already in use.
		for (int i = 0; i < ports.size(); ++i) {
			std::string portName = ports[i];
			std::cout << portName << std::endl;
			if (isPortOpen(portName)) {
				activePortName = portName;
				activePort = i-1; //Use with IMU
				//activePort = i;
			}
		}
		if (activePort == -1) {
			std::cerr << "Error! All ports are busy!" << std::endl;	
			exit(-1);
		} else {
			posPub_ = this->create_publisher<std_msgs::msg::String>("motors" + std::to_string(activePort), 10);
			timer_ = this->create_wall_timer(20ms, std::bind(&MSM::comLoop, this));
			homePub_ = this->create_publisher<std_msgs::msg::Bool>("is_homing", 10);
			loadSettings();
			initComm();
			//comLoop();
		}
	}
	
private:
	//Open a port, set the settings, and then the relevant start-up Q commands
	void initComm() {
		RCLCPP_INFO(this->get_logger(), "Selected port %i: %s", activePort, activePortName.c_str());

		v1 = 0.0;
		v2 = 0.0;
		v3 = 0.0;
		
		fd_ = open(activePortName.c_str(), O_RDWR | O_NOCTTY | O_SYNC);

		if (fd_ < 0) {
			std::cerr << "Couldn't re-open port" << std::endl;
			isRunning = false;
			exit(-1);
		}
		
		RCLCPP_INFO(this->get_logger(), "Applying port settings");
		setComSettings(fd_);
		startUpCommands(fd_);
		
	}

	//Main loop. Sends command, gets response. Alternates between set velocity command and get position command.
	void comLoop() {
		//printf("Comm loop\n");
		if (isRunning) { 
			auto isHoming = std_msgs::msg::Bool();
			isHoming.data = false;
			homePub_->publish(isHoming);
			if (updateLoop) {
				//Get position, store it
				sendCommand(fd_, std::to_string(m1i) + "IP");
				std::string res = std::string(getResponse(fd_));
				//std::cout << res << std::endl;
				std::string ps = split(res, "=")[1];
				//std::cout << ps << std::endl;
				
				p1 = stod(ps);
				
				sendCommand(fd_, std::to_string(m2i) + "IP");
				res = std::string(getResponse(fd_));
				//std::cout << res << std::endl;
				ps = split(res, "=")[1];
				//std::cout << ps << std::endl;
				p2 = stod(ps);
				
				sendCommand(fd_, std::to_string(m3i) + "IP");
				res = std::string(getResponse(fd_));
				ps = split(res, "=")[1];
				p3 = stod(ps);
				
				stateUpdate();
			} else {
				sendCommand(fd_, std::to_string(m1i) + "CS" + std::to_string(v1));
				char* res = getResponse(fd_);
				//std::cout << res << std::endl;
				sendCommand(fd_, std::to_string(m2i) + "CS" + std::to_string(v2));
				res = getResponse(fd_);
				
				sendCommand(fd_, std::to_string(m3i) + "CS" + std::to_string(v3));
				res = getResponse(fd_);
				//std::cout << res << std::endl;
				//Set velocity to latest stored one
			}
			
			updateLoop = !updateLoop;

			
		} else {
			//Kill motion once loop is dead
			std::string comm = std::to_string(m1i) + "SK";
			sendCommand(fd_, comm);
			char* res = getResponse(fd_);
		
			comm = std::to_string(m2i) + "SK";
			sendCommand(fd_, comm);
			res = getResponse(fd_);
			
			comm = std::to_string(m3i) + "SK";
			sendCommand(fd_, comm);
			res = getResponse(fd_);
			
			//Disable motors
			comm = std::to_string(m1i) + "MD";
			sendCommand(fd_, comm);
			getResponse(fd_);
			
			comm = std::to_string(m2i) + "MD";
			sendCommand(fd_, comm);
			getResponse(fd_);
			
			comm = std::to_string(m3i) + "MD";
			sendCommand(fd_, comm);
			getResponse(fd_);
			
			std::raise(SIGINT);
		}
		
	}
	
	//Get motor kinematic contraints from the settings file
	void loadSettings() {
		libconfig::Config cfg;
		std::string p = ament_index_cpp::get_package_prefix("motor_state_manager") + "/lib/motor_state_manager/motorsettings.cfg";
		std::cout << p << std::endl;
		try {
			cfg.readFile(p.c_str());
			if (activePort == 0) {
				//Motors 1 and 2
				m1i = 0;
				m2i = 1; //Comment this back to 1 when you've got a second motor
				m3i = 2;
				if (cfg.lookupValue("motor_1_max_acc", mac1) && cfg.lookupValue("motor_2_max_acc", mac2) && cfg.lookupValue("motor_3_max_acc", mac3) && cfg.lookupValue("motor_1_max_vel", mav1) && cfg.lookupValue("motor_2_max_vel", mav2) && cfg.lookupValue("motor_3_max_vel", mav3)) {
					std::cout << "Succesfully loaded motor settings\n";
				} else {
					std::cerr << "Error: Some settings are missing or have invalid types" << std::endl;
				}
				
			} else if (activePort == 1) {
				//Motors 3 and 4
				m1i = 2;
				m2i = 3;
				if (cfg.lookupValue("motor_3_max_acc", mac1) && cfg.lookupValue("motor_4_max_acc", mac2) && cfg.lookupValue("motor_3_max_vel", mav1) && cfg.lookupValue("motor_4_max_vel", mav2)) {
					std::cout << "Succesfully loaded motor settings\n\tmac1: \t\t" << mac1 << "\n\tmac2: \t\t" << mac2 << "\n\tmav1: \t\t" << mav1 << "\n\tmav2: \t\t" << mav2 << std::endl;
				} else {
					std::cerr << "Error: Some settings are missing or have invalid types" << std::endl;
				}	
			} else {
				//How???????
				RCLCPP_INFO(this->get_logger(), "Attempted to load settings for a set of motors that shouldn't exist? What's going on?");
			}
		} catch (const libconfig::FileIOException &e) {
			std::cerr << "Error reading the file: " << e.what() << std::endl;
		} catch (const libconfig::ParseException &e) {
			std::cerr << "Error parsing the file: " << e.what() << std::endl;
		} catch (const libconfig::SettingNotFoundException &e) {
			std::cerr << "Error: setting not found: " <<  e.what() << std::endl;
		} catch (const libconfig::SettingTypeException &e) {
			std::cerr << "Error: invalid setting type: " << e.what() << std::endl;
		}
	}
	
	//Function to blast the start-up commands.
	void startUpCommands(int serial_port) {
		std::string comm = std::to_string(m1i) + "AR"; //Alarm reset
		sendCommand(serial_port, comm);
		getResponse(serial_port);
		comm = std::to_string(m1i) + "ME"; //Motor enable
		sendCommand(serial_port, comm);
		getResponse(serial_port);
		comm = std::to_string(m1i) + "JA" + std::to_string(mac1); //Max accel
		sendCommand(serial_port, comm);
		getResponse(serial_port);
		comm = std::to_string(m1i) + "JL" + std::to_string(mac1); //Max decel
		sendCommand(serial_port, comm);
		getResponse(serial_port);
		comm = std::to_string(m1i) + "HA12"; //Homing acceleration step 1
		sendCommand(serial_port, comm);
		getResponse(serial_port);
		comm = std::to_string(m1i) + "HA22";//Homing acceleration step 2
		sendCommand(serial_port, comm);
		getResponse(serial_port);
		comm = std::to_string(m1i) + "HA32";//Homing acceleration step 3
		sendCommand(serial_port, comm);
		getResponse(serial_port); 
		comm = std::to_string(m1i) + "HL12";//Homing deceleration step 1
		sendCommand(serial_port, comm);
		getResponse(serial_port);
		comm = std::to_string(m1i) + "HL22";//Homing deceleration step 2
		sendCommand(serial_port, comm);
		getResponse(serial_port);
		comm = std::to_string(m1i) + "HL32";//Homing deceleration step 3
		sendCommand(serial_port, comm);
		getResponse(serial_port);
		comm = std::to_string(m1i) + "HV11";//Homing velocity step 1
		sendCommand(serial_port, comm);
		getResponse(serial_port);
		comm = std::to_string(m1i) + "HV21";//Homing velocity step 2
		sendCommand(serial_port, comm);
		getResponse(serial_port);
		comm = std::to_string(m1i) + "HV31";//Homing velocity step 3
		sendCommand(serial_port, comm);
		getResponse(serial_port);
		
		//Same as above but for second motor
		comm = std::to_string(m2i) + "AR";
		sendCommand(serial_port, comm);
		getResponse(serial_port);
		comm = std::to_string(m2i) + "ME";
		sendCommand(serial_port, comm);
		getResponse(serial_port);
		comm = std::to_string(m2i) + "JA" + std::to_string(mac2);
		sendCommand(serial_port, comm);
		getResponse(serial_port);
		comm = std::to_string(m2i) + "JL" + std::to_string(mac2);
		sendCommand(serial_port, comm);
		getResponse(serial_port);
		comm = std::to_string(m2i) + "HA12";
		sendCommand(serial_port, comm);
		getResponse(serial_port);
		comm = std::to_string(m2i) + "HA22";
		sendCommand(serial_port, comm);
		getResponse(serial_port);
		comm = std::to_string(m2i) + "HA32";
		sendCommand(serial_port, comm);
		getResponse(serial_port); 
		comm = std::to_string(m2i) + "HL12";
		sendCommand(serial_port, comm);
		getResponse(serial_port);
		comm = std::to_string(m2i) + "HL22";
		sendCommand(serial_port, comm);
		getResponse(serial_port);
		comm = std::to_string(m2i) + "HL32";
		sendCommand(serial_port, comm);
		getResponse(serial_port);
		comm = std::to_string(m2i) + "HV11";
		sendCommand(serial_port, comm);
		getResponse(serial_port);
		comm = std::to_string(m2i) + "HV21";
		sendCommand(serial_port, comm);
		getResponse(serial_port);
		comm = std::to_string(m2i) + "HV31";
		sendCommand(serial_port, comm);
		getResponse(serial_port);
		
		//Same as above but for third motor
		comm = std::to_string(m3i) + "AR";
		sendCommand(serial_port, comm);
		getResponse(serial_port);
		comm = std::to_string(m3i) + "ME";
		sendCommand(serial_port, comm);
		getResponse(serial_port);
		comm = std::to_string(m3i) + "JA" + std::to_string(mac3);
		sendCommand(serial_port, comm);
		getResponse(serial_port);
		comm = std::to_string(m3i) + "JL" + std::to_string(mac3);
		sendCommand(serial_port, comm);
		getResponse(serial_port);
		comm = std::to_string(m3i) + "HA12";
		sendCommand(serial_port, comm);
		getResponse(serial_port);
		comm = std::to_string(m3i) + "HA22";
		sendCommand(serial_port, comm);
		getResponse(serial_port);
		comm = std::to_string(m3i) + "HA32";
		sendCommand(serial_port, comm);
		getResponse(serial_port); 
		comm = std::to_string(m3i) + "HL12";
		sendCommand(serial_port, comm);
		getResponse(serial_port);
		comm = std::to_string(m3i) + "HL22";
		sendCommand(serial_port, comm);
		getResponse(serial_port);
		comm = std::to_string(m3i) + "HL32";
		sendCommand(serial_port, comm);
		getResponse(serial_port);
		comm = std::to_string(m3i) + "HV11";
		sendCommand(serial_port, comm);
		getResponse(serial_port);
		comm = std::to_string(m3i) + "HV21";
		sendCommand(serial_port, comm);
		getResponse(serial_port);
		comm = std::to_string(m3i) + "HV31";
		sendCommand(serial_port, comm);
		getResponse(serial_port);
		
		homeMotors(serial_port);
	}
	
	//Listen for velocity commands from head_chef
	void commands(const std_msgs::msg::String& msg) {
		char cTarg = msg.data.c_str()[0];
		int iTarg = (int) (cTarg - '0');
		//std::cout << msg.data.c_str() << std::endl;
		char sCom = msg.data.c_str()[1];
		if (sCom == ' ') {
			if (iTarg == activePort) {
				std::string comm = split(msg.data, " ")[1];
				std::vector<std::string> vels = split(comm, ",");
				v1 = std::max(std::min(stod(vels[0]), mav1), -mav1);
				v2 = std::max(std::min(stod(vels[1]), mav2), -mav2);
				v3 = std::max(std::min(stod(vels[2]), mav3), -mav3);
			}
		} else if (sCom == 'H') {
			homeMotors(fd_);
		}
	}
	
	//Do some homing maybe
	void homeMotors(int serial_port) {
		//Home motor 0
		auto isHoming = std_msgs::msg::Bool();
		isHoming.data = true;
		homePub_->publish(isHoming);
		std::string comm = std::to_string(m1i) + "CS0"; //Set velocity to 0
		sendCommand(serial_port, comm);
		getResponse(serial_port);
		comm = std::to_string(m1i) + "SJ";
		sendCommand(serial_port, comm);
		getResponse(serial_port);
		/*
		comm = std::to_string(m1i) + "HS0";
		sendCommand(serial_port, comm);
		getResponse(serial_port);
		bool isHoming = true;
		do {
			comm = std::to_string(m1i) + "WM";
			sendCommand(serial_port, comm);
			char* res = getResponse(serial_port);
			if (res[1] == '%') {
				isHoming = false;
			}
		} while (isHoming);
		comm = std::to_string(m1i) + "SP0"; //Set this new homed position as 0
		sendCommand(serial_port, comm);
		getResponse(serial_port);
		*/
		homePub_->publish(isHoming);
		comm = std::to_string(m1i) + "CJ"; //Go to set velocity (start 0)
		sendCommand(serial_port, comm);
		getResponse(serial_port);
		comm = std::to_string(m1i) + "CS0"; //Set velocity to 0
		sendCommand(serial_port, comm);
		getResponse(serial_port);
		
		//Home motor 1
		comm = std::to_string(m2i) + "CS0"; //Set velocity to 0
		sendCommand(serial_port, comm);
		getResponse(serial_port);
		comm = std::to_string(m2i) + "SJ";
		sendCommand(serial_port, comm);
		getResponse(serial_port);
		/*
		comm = std::to_string(m2i) + "HS0";
		sendCommand(serial_port, comm);
		getResponse(serial_port);
		isHoming = true;
		do {
			comm = std::to_string(m2i) + "WM";
			sendCommand(serial_port, comm);
			char* res = getResponse(serial_port);
			if (res[1] == '%') {
				isHoming = false;
			}
		} while (isHoming);
		
		comm = std::to_string(m2i) + "SP0"; //Set this new homed position as 0
		sendCommand(serial_port, comm);
		getResponse(serial_port);
		*/
		homePub_->publish(isHoming);
		comm = std::to_string(m2i) + "CJ"; //Go to set velocity (start 0)
		sendCommand(serial_port, comm);
		getResponse(serial_port);
		
		comm = std::to_string(m2i) + "CS0"; //Set velocity to 0
		sendCommand(serial_port, comm);
		getResponse(serial_port);
		
		//Home motor 2
		comm = std::to_string(m3i) + "CS0"; //Set velocity to 0
		sendCommand(serial_port, comm);
		getResponse(serial_port);
		comm = std::to_string(m3i) + "SJ";
		sendCommand(serial_port, comm);
		getResponse(serial_port);
		/*
		comm = std::to_string(m3i) + "HS0";
		sendCommand(serial_port, comm);
		getResponse(serial_port);
		isHoming = true;
		do {
			comm = std::to_string(m3i) + "WM";
			sendCommand(serial_port, comm);
			char* res = getResponse(serial_port);
			if (res[1] == '%') {
				isHoming = false;
			}
		} while (isHoming);
		
		comm = std::to_string(m3i) + "SP0"; //Set this new homed position as 0
		sendCommand(serial_port, comm);
		getResponse(serial_port);
		*/
		homePub_->publish(isHoming);
		comm = std::to_string(m3i) + "CJ"; //Go to set velocity (start 0)
		sendCommand(serial_port, comm);
		getResponse(serial_port);
		
		comm = std::to_string(m3i) + "CS0"; //Set velocity to 0
		sendCommand(serial_port, comm);
		getResponse(serial_port);
		
		isHoming.data = false;
		homePub_->publish(isHoming);
		
	}
	
	void stateUpdate() {
		auto message = std_msgs::msg::String();
		message.data = std::to_string(p1) + "," + std::to_string(p2) + "," + std::to_string(p3);
		posPub_->publish(message);
	}
	
	std::vector<std::string> ports;
	int activePort = -1;
	std::string activePortName;
	
	//Positions and velocities of the motors
	double p1, p2, p3;
	double v1, v2, v3;
	
	//Serial indicies of the motors
	int m1i = 0;
	int m2i = 0;
	int m3i = 0;
	
	//Serial port in use
	int fd_ = 0;
	
	//Kinematics
	double mac1 = 1.0;
	double mac2 = 1.0; //Maximum accel / decel
	double mac3 = 1.0;
	double mav1 = 1.0;
	double mav2 = 1.0; //Maximum velocity
	double mav3 = 1.0;
	bool updateLoop;

	//Subscriptions and publications for rviz2
	rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_;
	rclcpp::Publisher<std_msgs::msg::String>::SharedPtr posPub_;
	rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr homePub_;
	rclcpp::TimerBase::SharedPtr timer_;

};


int main(int argc, char ** argv) {
	rclcpp::init(argc, argv);
	signal(SIGINT, signal_callback_handler);
	rclcpp::spin(std::make_shared<MSM>());
	
	rclcpp::shutdown();
	return 0;
}
