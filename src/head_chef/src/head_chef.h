#ifndef HEAD_CHEF_H
#define HEAD_CHEF_H

#include <cstdio>
#include <memory>
#include <chrono>
#include <thread>
#include <functional>
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/bool.hpp"
#include "geometry_msgs/msg/quaternion.hpp"
#include "geometry_msgs/msg/quaternion_stamped.hpp"
#include "sensor_msgs/msg/joint_state.hpp"
#include "tf2_geometry_msgs/tf2_geometry_msgs.hpp"
#include "tf2_ros/transform_broadcaster.h"
#include "seastar_interfaces/msg/sky_ephemeris.hpp"
#include "seastar_interfaces/msg/desired_pointing.hpp"
#include "seastar_interfaces/msg/motor_command.hpp"
#include "seastar_interfaces/srv/point_motors.hpp"
#include "sousChef.h"
#include "PID.h"
#include "ChefScript.h"

class ChefScript;

class HeadChef : public rclcpp::Node {
public:
	HeadChef();
	
	//Function calls for ChefScript
	void homeAll();
	void findSun();
	void findSunFor(double t);
	void trackSunFor(double t);
	void setSolarAzOff(double off);
	void setSolarAltOff(double off);
	void setSolarPolar(double pol);
	void setSTargAz(double az);
	void setSTargAlt(double alt);
	void setSTargPol(double pol);
	void findTarg();
	void findStayTarg(double t);
	void setArcStart(double start);
	void setArcEnd(double end);
	void arcSun(double size);
	void arcTarg(double size);
	
	//Functions used for ChefScript calls
	void checkSunTimer();
	void seekLoopPos();
	void seekArcPos();
	
	void homeUpdate(const std_msgs::msg::Bool& msg);
	
	//Listen for the first motor_state_manager to publish the positions of the roll and pitch motors
	void firstPairListener(const std_msgs::msg::String& msg);
	//Listen for the second motor_state_manager to publish the stokes and plate positions
	void secondPairListener(const std_msgs::msg::String& msg);
	
	//Listen for the ik_tools inverse jacobian, and if the mode is right, use it to follow the sun.
	void jacUpdate(const std_msgs::msg::String& msg);
	
	//Listen for the ik_tools publication of where the robot thinks its pointing, for tracking the offset in the IMU
	void roboEphemUpdate(const seastar_interfaces::msg::SkyEphemeris& msg);
	//Get the solar ephemeris, and then rotate it by the IMU's rotation
	void ephemUpdate(const seastar_interfaces::msg::SkyEphemeris& msg);
	
	//Get the location of the sun spot and store where on the camera it is
	//Function probably not needed anymore and is computed in ik_tools but too lazy to remove all references to it
	void sunUpdate(const std_msgs::msg::String& msg);
	
	//Here we communicate with the motor_state_manager, giving in the desired velocity commands from either the inverse jacobian or the PIDs
	void orderMotors();
	
	//Call the relevant commands depending on the current mode.
	void cook();
	
	//Will draw circle around sun
	void loopSun(double size);
	void loopTarg(double size);
	
	//Logs data for debugging. 
	void logSunData();
	//Gets current values, packages them together, and sends request off to ik_solver
	void seekSun();
	//The same but for the secondary target
	void seekSTarg();
	
	//Once the IK has been solved, this catches the reply and sets the relevant commands. Also tracks percent error for fun and for knowing when a point has been reached.
	void use_ik(rclcpp::Client<seastar_interfaces::srv::PointMotors>::SharedFuture future);
	
	//Used to be used to follow the sun. Not really needed now, artifact I'm too lazy to delete
	void followSun();
	
	//Publishes all the joint states in case we want to view what's happening with rviz2
	void publishJointState();
	
	//Old function to convert roll motor encoded positions to degrees. Not really needed.
	double encodeToPos1(double enc);
	//Old function to convert pitch motor encoded positions to degrees. Not really needed.
	double encodeToPos2(double enc);
	//Old function to convert stokes motor encoded positions to degrees. Not really needed.
	double encodeToPos3(double enc);
	
	//Currently used function to convert encoder position to degrees
	double encToAng(double enc);
	
	//Currently used function to convert degrees to encoder positions
	double angToEnc(double ang);
	//Listens for the orientation of the IMU, and then takes the inverse of the quaternion, to undo any rotation it sees
	void imuUpdate(const geometry_msgs::msg::QuaternionStamped msg);
	
	
	//Define all our subscriptions, publications, and whatnot.
	rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub1_;
	rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub2_;
	rclcpp::Subscription<seastar_interfaces::msg::SkyEphemeris>::SharedPtr ephemSub_;
	rclcpp::Subscription<seastar_interfaces::msg::SkyEphemeris>::SharedPtr roboEphemSub_;
	rclcpp::Subscription<geometry_msgs::msg::QuaternionStamped>::SharedPtr imuSub_;
	rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sunSub_;
	rclcpp::Subscription<std_msgs::msg::String>::SharedPtr jacSub_;
	rclcpp::Publisher<std_msgs::msg::String>::SharedPtr commPub_;
	rclcpp::TimerBase::SharedPtr timer_;
	rclcpp::Client<seastar_interfaces::srv::PointMotors>::SharedPtr client_;
	rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr homeSub_;
	
	//Internal tracking varials
	double motorPs[4]; //Current positions of the motors in encoder space
	double desiredMotorPs[4]; //Target positions of the motors in encoder space
	double commVels[4]; //Current commanded velocities of the motors, to be published
	
	double solarAz = 0.0; //Current solar azimuth
	double solarAlt = 0.0; //Current solar altitude
	double solarPol = 0.0;
	
	double camX = 0.0; //Sun spot on the camera x
	double camY = 0.0; //Sun spot on the camera y
	
	double camW = 640.0; //Camera dimensions for math
	double camH = 480.0;
	
	double azOff = 0.0; //Offsets to azimuth / altitude for tracking
	double altOff = 0.0;
	
	PID pid1; //PID controllers for the motors
	PID pid2;
	PID pid3;
	
	ChefScript cs; //Reads and executes recipe
	bool doneWithCommand = true;
	
	//I don't really remember what this does but I don't like deleting things
	int iLoop = 0;
	
	//Current orientation of the IMU
	Quat imu = {0.0, 0.0, 0.0, 1.0};
	Vector3 solarVecS = {1.0, 1.0, 1.0}; //Vector representing the solar ephemeris Subscribed in the topic
	Vector3 solarVecC = {1.0, 1.0, 1.0}; //Vector representing the solar ephemeris Corrected by the IMU
	
	Vector3 sTargVecS = {1.0, 0.0, 0.0};
	Vector3 sTargVecC = {1.0, 0.0, 0.0};
	
	ChefMode mode = IKTest; //Current chef mode
	//ChefMode mode = WaitForComm;
	
	//ChefMode mode = SunSeeking;
	bool openedLog = false; //Track if we have the log open, and if we need to close it
	std::ofstream logFile; //The log
	
	//More publishers used for visualization in rviz2
	rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr joint_pub_;
	std::shared_ptr<tf2_ros::TransformBroadcaster> broadcaster_;
	sensor_msgs::msg::JointState joint_state_;
	
	std::chrono::time_point<std::chrono::high_resolution_clock> start_;

	double targTime = 0.0;
	double circRad = 0.0;
	double arcStart = 0.0;
	double arcEnd = 360.0;
	int loopStep = 0;
	int loopMax = 100;
	
	double commSolarAzOff = 0.0;
	double commSolarAltOff = 0.0;
	
	double sTargAz = 0.0;
	double sTargAlt = 0.0;
	double sTargPol = 0.0;
};

#endif
