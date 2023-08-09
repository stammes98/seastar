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
			printf("PID settings succesfully loaded from %s.\n", fileName.c_str());
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
