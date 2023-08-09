#ifndef PID_H
#define PID_H

#include <stdio.h>
#include <float.h>
#include <chrono>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <fstream>

#define INTEGRAL_CLAMP 50000.0

//My custom PID implemented class. Most function names are self explaining. Best practice is to use the longer definitions
//The derivative terms use timers, dt is the difference in time between the prior call to update() and the current call to update()

class PID {
public:
	PID();
	PID(double p, double i, double d);
	PID(double p, double i, double d, double minVal, double maxVal);
	PID(double p, double i, double d, double minVal, double maxVal, double setPoint);
	double update(double input, bool verbose=false);
	void setSetpoint(double value);
	double getSetpoint();
	void setP(double p);
	void setI(double i);
	void setD(double d);
	double getP();
	double getI();
	double getD();
	void setMin(double minVal);
	void setMax(double maxVal);
	double getMin();
	double getMax();
	void enableLog();
	void closeLog();
	double getErr();
	
private:
	double p_, i_, d_;
	double minVal_ = -DBL_MAX/2;
	double maxVal_ = DBL_MAX/2;
	double setpoint_;
	std::chrono::time_point<std::chrono::high_resolution_clock> start_;
	std::chrono::time_point<std::chrono::high_resolution_clock> end_;
	double dt_;
	double integral_ = 0.0;
	double err_ = 0.0;
	double lastErr_ = 0.0;
	bool doLogging = false;
	bool hasStarted = false;
	std::ofstream outFile;
	std::chrono::time_point<std::chrono::high_resolution_clock> logStart_;
	
};

#endif
