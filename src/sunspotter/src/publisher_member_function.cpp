#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <cv_bridge/cv_bridge.h>

using namespace std::chrono_literals;
using namespace cv;

//Interfaces with camera

class MinimalPublisher : public rclcpp::Node {
public:
	MinimalPublisher() : Node("minimal_publisher"), count_(0) {
		imPublisher_ = this->create_publisher<sensor_msgs::msg::Image>("proc_image", 10);
		strPublisher_ = this->create_publisher<std_msgs::msg::String>("sunspot", 10);
		timer_ = this->create_wall_timer(20ms, std::bind(&MinimalPublisher::timer_callback, this));
		cap_.open(0, CAP_V4L2);
		if (!cap_.isOpened()) {
			printf("Failed to find camera!\n");
			exit(-1);
		}
		
		//Use v4l2 to get feed in 50 fps
		system("v4l2-ctl -d /dev/video0 -v pixelformat='MJPG'");
		
		//Set video format and settings
		cap_.set(CAP_PROP_FOURCC, VideoWriter::fourcc('M', 'J', 'P', 'G'));
		cap_.set(CAP_PROP_MODE, 0);
		cap_.set(CAP_PROP_FRAME_WIDTH, 640);
		cap_.set(CAP_PROP_FRAME_HEIGHT, 480);
		cap_.set(CAP_PROP_FPS, 50.0);
		
		//Need this command for some reason
		//Window doesn't actually ever appear, but node doesn't work without this line
		namedWindow("Display");
		
	}
	
private:
	void timer_callback() {
		//Read latest data from the camera
		cap_ >> frame_;
		Mat greyMat;
		//Convert it into what OpenCV knows as Gray
		cvtColor(frame_, greyMat, COLOR_BGR2GRAY);
		if (frame_.empty()) {
			printf("Empty frame!\n");
			exit(-1);
		}
		//Apply our gaussian blur
		Mat newFrame;
		GaussianBlur(greyMat, newFrame, Size(blurRad_, blurRad_), 0); 
		//Get brightest location
		Point minLoc(0, 0), maxLoc(0, 0);
		minMaxLoc(newFrame, 0, 0, &minLoc, &maxLoc);
		//Draw a circle around it
		circle(frame_, maxLoc, 10, Scalar(0, 0, 0), 2);
		imshow("Display", frame_);
		//Publish the unblurred one with the circle
		msg_ = cv_bridge::CvImage(std_msgs::msg::Header(), "bgr8", frame_).toImageMsg();
		
		imPublisher_->publish(*msg_.get());
		//RCLCPP_INFO(this->get_logger(), "Image %ld published", count_);
		count_++; //Not sure why we still have a counter.
		//Publish location of the brightest pixel
		auto message = std_msgs::msg::String();
		message.data = std::to_string(maxLoc.x) + "," + std::to_string(maxLoc.y);
		strPublisher_->publish(message);

		//RCLCPP_INFO(this->get_logger(), "Publishing: %s", message.data.c_str());
		//imPublisher_->publish(message); 
	}
	rclcpp::TimerBase::SharedPtr timer_;
	sensor_msgs::msg::Image::SharedPtr msg_;
	rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr imPublisher_;
	rclcpp::Publisher<std_msgs::msg::String>::SharedPtr strPublisher_;
	size_t count_;
	VideoCapture cap_;
	Mat frame_;
	const int blurRad_ = 151; //Radius of Gaussian blur. Bigger value = more accurate, less fast
};

int main(int argc, char* argv[]) {
	rclcpp::init(argc, argv);
	rclcpp::spin(std::make_shared<MinimalPublisher>());
	rclcpp::shutdown();
	return 0;
}
