#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <libconfig.h++>
#include <Eigen/Dense>
#include "PID.h"

using Eigen::Map;
using Eigen::MatrixXd;
using Eigen::MatrixXf;
using Eigen::Vector3f;
using Eigen::VectorXf;

#ifndef SOUS_CHEF_H
#define SOUS_CHEF_H

#define PI 3.14159265359
#define DEG2RAD(a)		(a * PI / 180)
#define RAD2DEG(a)		(a * 180 / PI)

enum ChefMode { 
	Homing,
	WaitForComm,
	SunSeeking,
	SunSeekingTimer,
	SunSeekingTest,
	SunTracking,
	SunTrackingTest,
	DrawCircleSun,
	DrawCircleTarg,
	TargSeeking,
	TargSeekingTimer,
	DrawArcSun,
	DrawArcTarg,
	PIDTest,
	IKTest,
	Shutdown
};

struct Vector3 {
	double x;
	double y;
	double z;
};

struct Vector6 {
	double x;
	double y;
	double z;
	double a;
	double b;
	double c;
};

struct Quat {
	double x;
	double y;
	double z;
	double w;
};

struct MotorState {
	double q1;
	double q2;
	double q3;
};

struct Mat3 {
	double m11;
	double m12;
	double m13;
	double m21;
	double m22;
	double m23;
	double m31;
	double m32;
	double m33;
};

struct Mat6 {
	double m11;
	double m12;
	double m13;
	double m21;
	double m22;
	double m23;
	double m31;
	double m32;
	double m33;
	double m41;
	double m42;
	double m43;
	double m51;
	double m52;
	double m53;
	double m61;
	double m62;
	double m63;
};

const double EPS_ = 1e-12;

//Split a string into a vector of strings given a token
std::vector<std::string> split(std::string s, std::string delimiter);
//Faster way to use the split function and split two doubles
double* motorStates(std::string input);
//Faster way to use the split function and split three doubles
double* trackingStates(std::string input);

//Convert a vector from spherical coordinates to cartesian
Vector3 toCart(const Vector3& spherical);
//Convert a vector from cartesian coordinates to spherical
Vector3 toSpher(const Vector3& cart);

//Rotate a vector in spherical coordinates by a quaternion
Vector3 rotateSpher(const Vector3& spherical, const Quat& quat);
//Rotate a vector in cartesian coordiantes by a quaternion
Vector3 rotateCart(const Vector3& cart, const Quat& quat);

//Hamiltonian product of vector and quaternion
Quat hamProd(const Vector3& vec, const Quat& q);
//Hamiltonian product of quaternion and quaternion
Quat hamiltonianProduct(const Quat& q1, const Quat& q2);
//Alternative formulation of hamiltonian product
Quat multQuat(const Quat& q1, const Quat& q2);

//Dot product of two vectors
double dot(const Vector3& v1, const Vector3& v2);
//Cross product of two vectors
Vector3 cross(const Vector3& v1, const Vector3& v2);
//Perform scalar multiplication on vectors (can't do it the default way because I got lazy and used a quick and dirty struct instead of a class)
Vector3 scalarMult(const Vector3& vec, const double k);

//Undo whatever nonsense Microsoft does to quaternions
Quat fixQuat(const Quat& q);

//Load settings into a PID
PID getFromFile(std::string filePath);

Vector6 getPoseErr(Mat3 targ, Mat3 cur);
double getErrPose(Mat3 targ, Mat3 cur);
Vector3 rot_to_omega(Mat3 R);

Mat3 motor1(double q);
Mat3 motor2(double q);
Mat3 motor3(double q);

Mat3 doFk(double q1, double q2, double q3);
Mat3 sunMat(double az, double alt);

Mat3 transpose(Mat3 mat);
Mat3 dotMats(Mat3 a, Mat3 b);
Mat6 getJacobian(double q1, double q2, double q3);

Vector3 matDotVec(Mat3 a, Vector3 b);

MotorState doIk(double tAz, double tAlt, double polar);

#endif
