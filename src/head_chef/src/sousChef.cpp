#include "sousChef.h"

std::vector<std::string> split(std::string s, std::string delimiter) {
	size_t pos_start = 0, pos_end, delim_len = delimiter.length();
	std::string token;
	std::vector<std::string> res;
	
	while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
		token = s.substr(pos_start, pos_end - pos_start);
		pos_start = pos_end + delim_len;
		res.push_back(token);
	}
	res.push_back(s.substr(pos_start));
	return res;
}

double* motorStates(std::string input) {
	static double res[2] = {0.0, 0.0};
	std::vector<std::string> sVs = split(input, ",");
	res[0] = stod(sVs[0]);
	res[1] = stod(sVs[1]);
	return res;
}

double* trackingStates(std::string input) {
	static double res[3] = {0.0, 0.0, 0.0};
	std::vector<std::string> sVs = split(input, ",");
	res[0] = stod(sVs[0]);
	res[1] = stod(sVs[1]);
	res[2] = stod(sVs[2]);
	return res;
}

Vector3 toCart(const Vector3& spherical) {
	double r = spherical.x;
	double theta = spherical.y;
	double phi = spherical.z;
	
	double x = r * sin(phi) * cos(theta);
	double y = r * sin(theta) * sin(phi);
	double z = r * cos(phi);
	
	return {x, y, z};
}

Vector3 toSpher(const Vector3& cart) {
	double r = sqrt((cart.x * cart.x) + (cart.y * cart.y) + (cart.z * cart.z));
	double phi = acos(cart.z / r);
	double theta = atan(cart.y / cart.x);
	return {r, theta, phi};
}

Vector3 rotateSpher(const Vector3& spherical, const Quat& quat) {
	Vector3 cart = toCart(spherical);
	return toSpher(rotateCart(cart, quat));
}


Vector3 rotateCart(const Vector3& cart, const Quat& quat) {
	
	Quat invQuat = {-quat.x, -quat.y, -quat.z, quat.w};
	Quat cartQuat = {cart.x, cart.y, cart.z, 0};
	Quat rPrimeQ = hamiltonianProduct(hamiltonianProduct(quat, cartQuat), invQuat);
	Vector3 rPrime = {rPrimeQ.x, rPrimeQ.y, rPrimeQ.z};
	return rPrime;
	
}

//Hamiltonian product I swear I'm not hungry
Quat hamProd(const Vector3& vec, const Quat& q) {
	Quat result;
	result.x = q.w * vec.x + q.y * vec.z - q.z * vec.y;
	result.y = q.w * vec.y + q.z * vec.x - q.x * vec.z;
	result.z = q.w * vec.z + q.x * vec.y - q.y * vec.x;
	result.w = -q.x * vec.x - q.y * vec.y - q.z * vec.z;
	return result;
}

Quat hamiltonianProduct(const Quat& q1, const Quat& q2) {
	Quat res;
	double a1 = q1.w;
	double a2 = q2.w;
	double b1 = q1.x;
	double b2 = q2.x;
	double c1 = q1.y;
	double c2 = q2.y;
	double d1 = q1.z;
	double d2 = q2.z;
	
	
	
	res.w = (a1 * a2) - (b1 * b2) - (c1 * c2) - (d1 * d2);
	res.x = (a1 * b2) + (b1 * a2) + (c1 * d2) - (d1 * c2);
	res.y = (a1 * c2) - (b1 * d2) + (c1 * a2) + (d1 * b2);
	res.z = (a1 * d2) + (b1 * c2) - (c1 * b2) + (d1 * a2);
	return res;
}

Quat multQuat(const Quat& q1, const Quat& q2) {
	Quat result;
	result.x = q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y;
	result.y = q1.w * q2.y + q1.y * q2.w + q1.z * q2.x - q1.x * q2.z;
	result.z = q1.w * q2.z + q1.x * q2.y - q1.y * q2.x + q1.z * q2.w;
	result.w = q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z;
	return result;
}

double dot(const Vector3& v1, const Vector3& v2) {
	return ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z));
}

Vector3 cross(const Vector3& v1, const Vector3& v2) {
	double iHat = (v1.y * v2.z) - (v1.z * v2.y);
	double jHat = (v1.z * v2.x) - (v1.x * v2.z);
	double kHat = (v1.x * v2.y) - (v1.y * v2.x);
	return {iHat, jHat, kHat};
}

Vector3 scalarMult(const Vector3& vec, const double k) {
	return {vec.x * k, vec.y * k, vec.z * k};
}

Quat fixQuat(const Quat& q) {
	double sinr_cosp = 2 * (q.w * q.x + q.y * q.z);
	double cosr_cosp = 1 - 2 * (q.x * q.x + q.y * q.y);
	double sinp = sqrt(1 + 2 * (q.w * q.y - q.x * q.x));
	double cosp = sqrt(1 - 2 * (q.w * q.y - q.x * q.z));
	double siny_cosp = 2 * (q.w * q.z + q.x * q.y);
	double cosy_cosp = 1 - 2 * (q.y * q.y + q.z * q.z);
	
	double roll = atan2(sinr_cosp, cosr_cosp);
	double pitch = 2 * atan2(sinp, cosp) - (PI / 2);
	double yaw = atan2(siny_cosp, cosy_cosp);
	
	printf("roll: %f\npitch: %f\nyaw: %f\n\n", RAD2DEG(roll), RAD2DEG(pitch), RAD2DEG(yaw));
	
	//roll = roll;
	//yaw = -yaw;
	
	
	//yaw = yaw;
	
	double cr = cos(roll * 0.5);
	double sr = sin(roll * 0.5);
	double cp = cos(pitch * 0.5);
	double sp = sin(pitch * 0.5);
	
	
	/*
	double cr = cos(pitch * 0.5);
	double sr = sin(pitch * 0.5);
	double cp = cos(roll * 0.5);
	double sp = sin(roll * 0.5); //Switcheroo
	*/
	
	double cy = cos(yaw * 0.5);
	double sy = sin(yaw * 0.5);
	
	Quat res;
	res.w = cr * cp * cy + sr * sp * sy;
	res.x = sr * cp * cy - cr * sp * sy;
	res.y = cr * sp * cy + sr * cp * sy;
	res.z = cr * cp * sy - sr * sp * cy;
	return res;
}

PID getFromFile(std::string filePath) {
	//p, i, d, min, max
	double p, i, d, min, max;
	libconfig::Config cfg;
	
	try {
		cfg.readFile(filePath.c_str());
		if (cfg.lookupValue("p", p) && cfg.lookupValue("i", i) && cfg.lookupValue("d", d) && cfg.lookupValue("min", min) && cfg.lookupValue("max", max)) {
			printf("PID settings succesfully loaded from %s.\n", filePath.c_str());
		} else {
			printf("ERROR: PID settings unable to be loaded from %s\n", filePath.c_str());
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
	return PID(p, i, d, min, max);
}

Vector3 rot_to_omega(Mat3 R) {
	Vector3 el;
	Vector3 res;
	el.x = R.m32 - R.m23;
	el.y = R.m13 - R.m31;
	el.z = R.m21 - R.m12;
	
	double traceR = R.m11 + R.m22 + R.m33;
	
	double norm_el = sqrt((el.x * el.x) + (el.y * el.y) + (el.z * el.z));
	if (norm_el > EPS_) {
		double s1 = atan2(norm_el, traceR) / norm_el;
		res.x = el.x * s1;
		res.y = el.y * s1;
		res.z = el.z * s1;
	} else if (R.m11 > 0 && R.m22 > 0 and R.m33 > 0) {
		res.x = 0.0;
		res.y = 0.0;
		res.z = 0.0;
	} else {
		double s1 = PI / 2;
		res.x = s1 * (R.m11 + 1.0);
		res.y = s1 * (R.m22 + 1.0);
		res.z = s1 * (R.m33 + 1.0);
	}
	return res;
}



Vector3 matDotVec(Mat3 a, Vector3 b) {
	Vector3 res;
	res.x = (a.m11 * b.x) + (a.m12 * b.y) + (a.m13 * b.z);
	res.y = (a.m21 * b.x) + (a.m22 * b.y) + (a.m23 * b.z);
	res.z = (a.m31 * b.x) + (a.m32 * b.y) + (a.m33 * b.z);
	return res;
}

Mat3 transpose(Mat3 mat) {
	Mat3 res;
	res.m11 = mat.m11;
	res.m12 = mat.m21;
	res.m13 = mat.m31;
	res.m21 = mat.m12;
	res.m22 = mat.m22;
	res.m23 = mat.m32;
	res.m31 = mat.m13;
	res.m32 = mat.m23;
	res.m33 = mat.m33;
	return res;
}
Mat3 dotMats(Mat3 a, Mat3 b) {
	Mat3 res;
	res.m11 = (a.m11 * b.m11) + (a.m12 * b.m21) + (a.m13 * b.m31);
	res.m12 = (a.m11 * b.m12) + (a.m12 * b.m22) + (a.m13 * b.m32);
	res.m13 = (a.m11 * b.m13) + (a.m12 * b.m23) + (a.m13 * b.m33);
	
	res.m21 = (a.m21 * b.m11) + (a.m22 * b.m21) + (a.m23 * b.m31);
	res.m22 = (a.m21 * b.m12) + (a.m22 * b.m22) + (a.m23 * b.m32);
	res.m23 = (a.m21 * b.m13) + (a.m22 * b.m23) + (a.m23 * b.m33);
	
	res.m31 = (a.m31 * b.m11) + (a.m32 * b.m21) + (a.m33 * b.m31);
	res.m32 = (a.m31 * b.m12) + (a.m32 * b.m22) + (a.m33 * b.m32);
	res.m33 = (a.m31 * b.m13) + (a.m32 * b.m23) + (a.m33 * b.m33);  
	
	return res;
}

Vector6 getPoseErr(Mat3 targ, Mat3 cur) {
	Vector6 res;
	res.x = 0;
	res.y = 0;
	res.z = 0;
	Mat3 rot_err = dotMats(transpose(cur), targ);
	Vector3 w_err = matDotVec(cur, rot_to_omega(rot_err));
	res.a = w_err.x;
	res.b = w_err.y;
	res.c = w_err.z;
	return res;
}

double getErrPose(Mat3 targ, Mat3 cur) {
	Vector6 errVec = getPoseErr(targ, cur);
	return sqrt((errVec.x * errVec.x) + (errVec.y * errVec.y) + (errVec.z * errVec.z) + (errVec.a * errVec.a) + (errVec.b * errVec.b) + (errVec.c * errVec.c));
}

Mat3 doFk(double q1, double q2, double q3) {
	double s1 = sin(q1);
	double s2 = sin(q2);
	double s3 = sin(q3);
	double c1 = cos(q1);
	double c2 = cos(q2);
	double c3 = cos(q3);
	Mat3 res;
	res.m11 = s2 * s3;
	res.m12 = c3 * s2;
	res.m13 = c2;
	res.m21 = c1 * c2 * s3 - c3 * s1;
	res.m22 = c1 * c2 * c3 + s1 * s3;
	res.m23 = -c1 * s2;
	res.m31 = -c1 * c3 - c2 * s1 * s3;
	res.m32 = c1 * s3 - c2 * c3 * s1;
	res.m33 = s1 * s2;
	return res;
	
}
Mat3 sunMat(double az, double alt) {
	Mat3 res;
	res.m11 = cos(az) * cos(alt);
	res.m12 = -sin(az);
	res.m13 = cos(az) * sin(alt);
	res.m21 = sin(az) * cos(alt);
	res.m22 = cos(az);
	res.m23 = sin(az) * sin(alt);
	res.m31 = -sin(alt);
	res.m32 = 0.0;
	res.m33 = cos(alt);
	return res;
}

Mat3 motor1(double q) {
	Mat3 res;
	double s = sin(q);
	double c = cos(q);
	res.m11 = 0.0;
	res.m12 = -s;
	res.m13 = -c;
	res.m21 = 0.0;
	res.m22 = c;
	res.m23 = -s;
	res.m31 = 1.0;
	res.m32 = 0.0;
	res.m33 = 0.0;
	return res;
}

Mat3 motor2(double q) {
	return motor1(q);
}

Mat3 motor3(double q) {
	Mat3 res;
	double c = cos(q);
	double s = sin(q);
	res.m11 = c;
	res.m12 = -s;
	res.m13 = 0.0;
	res.m21 = s;
	res.m22 = c;
	res.m23 = 0.0;
	res.m31 = 0.0;
	res.m32 = 0.0;
	res.m33 = 1.0;
	return res;
}

Mat6 getJacobian(double q1, double q2, double q3) {
	Mat6 res;
	res.m11 = 0.0;
	res.m12 = 0.0;
	res.m13 = 0.0;
	res.m21 = 0.0;
	res.m22 = 0.0;
	res.m23 = 0.0;
	res.m31 = 0.0;
	res.m32 = 0.0;
	res.m33 = 0.0;
	Mat3 m1 = motor1(q1);
	Mat3 m2 = motor2(q2);
	Mat3 m3 = motor3(q3);
	
	std::cout << std::endl;
	std::cout << m1.m11 << " " << m1.m12 << " " << m1.m13 << std::endl;
	std::cout << m1.m21 << " " << m1.m22 << " " << m1.m23 << std::endl;
	std::cout << m1.m31 << " " << m1.m32 << " " << m1.m33 << std::endl;
	std::cout << std::endl;
	
	std::cout << std::endl;
	std::cout << m2.m11 << " " << m2.m12 << " " << m2.m13 << std::endl;
	std::cout << m2.m21 << " " << m2.m22 << " " << m2.m23 << std::endl;
	std::cout << m2.m31 << " " << m2.m32 << " " << m2.m33 << std::endl;
	std::cout << std::endl;
	
	std::cout << std::endl;
	std::cout << m3.m11 << " " << m3.m12 << " " << m3.m13 << std::endl;
	std::cout << m3.m21 << " " << m3.m22 << " " << m3.m23 << std::endl;
	std::cout << m3.m31 << " " << m3.m32 << " " << m3.m33 << std::endl;
	std::cout << std::endl;
	
	
	res.m41 = m1.m11;
	res.m51 = m1.m21;
	res.m61 = m1.m31;
	res.m42 = m2.m11;
	res.m52 = m2.m21;
	res.m62 = m2.m31;
	res.m43 = m3.m11;
	res.m53 = m3.m21;
	res.m63 = m3.m31;
	return res; 
	
}

MatrixXf computePseudoInverse(MatrixXf J)
{
    //MatrixXf J = jacobian(theta1, theta2, theta3);
    MatrixXf invJ = J.completeOrthogonalDecomposition().pseudoInverse();

    return invJ;
}

MotorState doIk(double tAz, double tAlt, double polar) {
	MotorState response;
	tAz += PI;
	tAlt *= -1;
	Mat3 targMat = sunMat(tAz, tAlt);
	double q1 = 0.0;
	double q2 = 0.0;
	double q3 = 0.0;
	
	Mat3 fk = doFk(q1, q2, q3);
	
	
	int DOF = 3;
	Vector6 err_pose = getPoseErr(targMat, fk);
	double err = getErrPose(targMat, fk);
	int iterator = 0;
	int max_iter = 1000;
	double lamb = 0.5;
	bool didSolve = true;
	double dq1 = 0.0;
	double dq2 = 0.0;
	double dq3 = 0.0;
	while (err > EPS_) {
		iterator++;
		if (iterator > max_iter) {
			didSolve = false;
			break;
		}
		Mat6 Jac = getJacobian(q1, q2, q3);
		//printf("Jac calculated. Pinv\n");
		std::cout << Jac.m11 << " " << Jac.m12 << " " << Jac.m13 << std::endl;
		std::cout << Jac.m21 << " " << Jac.m22 << " " << Jac.m23 << std::endl;
		std::cout << Jac.m31 << " " << Jac.m32 << " " << Jac.m33 << std::endl;
		std::cout << Jac.m41 << " " << Jac.m42 << " " << Jac.m43 << std::endl;
		std::cout << Jac.m51 << " " << Jac.m52 << " " << Jac.m53 << std::endl;
		std::cout << Jac.m61 << " " << Jac.m62 << " " << Jac.m63 << std::endl;
		MatrixXf J(3, 6);
		J(0, 0) = Jac.m11;
		J(1, 0) = Jac.m12;
		J(2, 0) = Jac.m13;
		J(0, 1) = Jac.m21;
		J(1, 1) = Jac.m22;
		J(2, 1) = Jac.m23;
		J(0, 2) = Jac.m31;
		J(1, 2) = Jac.m32;
		J(2, 2) = Jac.m33;
		J(0, 3) = Jac.m41;
		J(1, 3) = Jac.m42;
		J(2, 3) = Jac.m43;
		J(0, 4) = Jac.m51;
		J(1, 4) = Jac.m52;
		J(2, 4) = Jac.m53;
		J(0, 5) = Jac.m61;
		J(1, 5) = Jac.m62;
		J(2, 5) = Jac.m63;
		J.transposeInPlace();
		std::cout << J << std::endl;
		MatrixXf Jinv = computePseudoInverse(J);
		dq1 = lamb * ((Jinv(0, 0) * err_pose.x) + (Jinv(1, 0) * err_pose.y) + (Jinv(2, 0) * err_pose.z) + (Jinv(3, 0) * err_pose.a) + (Jinv(4, 0) * err_pose.b) + (Jinv(5, 0) * err_pose.c));
		dq2 = lamb * ((Jinv(0, 1) * err_pose.x) + (Jinv(1, 1) * err_pose.y) + (Jinv(2, 1) * err_pose.z) + (Jinv(3, 1) * err_pose.a) + (Jinv(4, 1) * err_pose.b) + (Jinv(5, 1) * err_pose.c));
		dq3 = lamb * ((Jinv(0, 2) * err_pose.x) + (Jinv(1, 2) * err_pose.y) + (Jinv(2, 2) * err_pose.z) + (Jinv(3, 2) * err_pose.a) + (Jinv(4, 2) * err_pose.b) + (Jinv(5, 2) * err_pose.c));
		printf("%f -- %f %f %f - %f %f %f\n", err, q1, q2, q3, dq1, dq2, dq3);
		q1 += dq1;
		q2 += dq2;
		q3 += dq3;
		fk = doFk(q1, q2, q3);
		err_pose = getPoseErr(targMat, fk);
		err = getErrPose(targMat, fk);
	}
	printf("Finished in %d iterations, err: %f\n", iterator, err);
	if (didSolve) {
		response.q1 = q1;
		response.q2 = q2;
		response.q3 = q3;
	} else {
		//response.q1 = 0.0;
		//response.q2 = 0.0;
		//response.q3 = 0.0;
	}
	return response;
}
