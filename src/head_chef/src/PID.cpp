#include "PID.h"

//We don't do anything here because when defining a PID such as
//PID pid1;
//Can be quite some time before being truly defined, which screws with the timer.
PID::PID() {

}

PID::PID(double p, double i, double d) : p_(p), i_(i), d_(d) {
	start_ = std::chrono::high_resolution_clock::now();
	end_ = std::chrono::high_resolution_clock::now();
	setpoint_ = 0.0;
}

PID::PID(double p, double i, double d, double minVal, double maxVal) : p_(p), i_(i), d_(d), minVal_(minVal), maxVal_(maxVal) {
	start_ = std::chrono::high_resolution_clock::now();
	end_ = std::chrono::high_resolution_clock::now();
	setpoint_ = 0.0;
}

PID::PID(double p, double i, double d, double minVal, double maxVal, double setPoint) : p_(p), i_(i), d_(d), minVal_(minVal), maxVal_(maxVal), setpoint_(setPoint) {
	start_ = std::chrono::high_resolution_clock::now();
	end_ = std::chrono::high_resolution_clock::now();
	setpoint_ = setPoint;
}


double PID::update(double input, bool verbose) {
	start_ = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = start_ - end_;
	end_ = start_;
	dt_ = diff.count();
	err_ = setpoint_ - input;
	
	if (!hasStarted) {
		hasStarted = true;
		dt_ = 0.25;
	}

	
	double Kp = (p_ * err_);
	integral_ += (err_ * dt_);
	integral_ = std::max(std::min((integral_), INTEGRAL_CLAMP), -INTEGRAL_CLAMP);
	double Ki = (i_ * integral_);
	double der = (err_ - lastErr_) / dt_;
	double Kd = (d_ * der);
	double out = std::max(std::min((Kp + Ki + Kd), maxVal_), minVal_);


	if (verbose) {
		printf("PID Update debug:\nP: %f\nI: %f\nD: %f\n", Kp, Ki, Kd);
		printf("setpoint: %f\n", setpoint_);
		//printf("p: %f\ni: %f\nd: %f\n", p_, i_, d_);
		printf("Out: %f\nintegral: %f\nerr: %f\nlastErr: %f\ndt: %f\nder: %f\n", out, integral_, err_, lastErr_, dt_, der);
		printf("dErr: %f\n", (err_ - lastErr_));
		printf("\n\n");
	}
	
	if (doLogging) {
		//outFile << "P, I, D, input, setpoint, err, dErr, int, t\n";
		std::chrono::duration<double> runTime = end_ - logStart_;
		outFile << Kp << ", " << Ki << ", " << Kd << ", " << input << ", " << setpoint_ << ", " << err_ << ", " << der << ", " << integral_ << ", "<< runTime.count() << std::endl;  
	}

	lastErr_ = err_;
	return out;
}

void PID::setSetpoint(double value) {
	setpoint_ = value;
}

double PID::getSetpoint() {
	return setpoint_;
}

void PID::setP(double p) {
	p_ = p;
}

void PID::setI(double i) {
	i_ = i;
}

void PID::setD(double d) {
	d_ = d;
}

double PID::getP() {
	return p_;
}

double PID::getI() {
	return i_;
}

double PID::getD() {
	return d_;
}

void PID::setMin(double minVal) {
	minVal_ = minVal;
}

void PID::setMax(double maxVal) {
	maxVal_ = maxVal;
}

double PID::getMax() {
	return maxVal_;
}

double PID::getMin() {
	return minVal_;
}

void PID::enableLog() {
	doLogging = true;
	logStart_ = std::chrono::high_resolution_clock::now();
	outFile.open("PID.csv");
	outFile << "P, I, D, input, setpoint, err, dErr, int, t\n";
}

void PID::closeLog() {
	outFile.close();
}

double PID::getErr() {
	return err_;
}
