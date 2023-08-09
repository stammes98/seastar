#include "helper.h"

//Write a string to a serial port
void sendCommand(int serial_port, std::string inString) {
	//printf("Sending command %s\n", inString.c_str());
	for (int i = 0; i < inString.length(); ++i) {
		char val[1] = {(char) inString[i]};
		write(serial_port, val, 1);
	}
	write(serial_port, "\r", 1);
}

//Listen for the response on a serial port
char* getResponse(int serial_port) {
	static char read_buf[256];
	memset(&read_buf, '\0', sizeof(read_buf));
	
	read(serial_port, &read_buf, sizeof(read_buf));
	//printf("Got response %s\n", read_buf);
	return read_buf;
}

//Set relevant serial settings
void setComSettings(int serial_port) {
	struct termios tty;
	if (tcgetattr(serial_port, &tty) != 0) {
		std::cerr << "Error " << errno << " from tcgetattr: " << strerror(errno) << std::endl;
	}
	cfsetispeed(&tty, B57600);
	cfsetospeed(&tty, B57600);
	
	//cfsetispeed(&tty, B38400);
	//cfsetospeed(&tty, B38400);
	
	tty.c_cflag &= ~PARENB;
	tty.c_cflag &= ~CSTOPB;
	tty.c_cflag &= ~CSIZE;
	tty.c_cflag |= CS8;
	tty.c_cflag &= ~CRTSCTS;
	tty.c_cflag |= CREAD | CLOCAL;
	
	tty.c_lflag &= ~ICANON;
	tty.c_lflag &= ~ECHO;
	tty.c_lflag &= ~ECHOE;
	tty.c_lflag &= ~ECHONL;
	tty.c_lflag &= ~IEXTEN;
	tty.c_lflag &= ~ISIG;
	
	tty.c_iflag &= ~(IXON | IXOFF | IXANY);
	tty.c_iflag &= ~(INLCR | ICRNL | IUCLC | IGNCR | INPCK);
	
	tty.c_oflag &= ~OPOST;
	tty.c_oflag &= ~ONLCR;
	
	tty.c_cc[VMIN] = 0;
	tty.c_cc[VTIME] = 5;
	
	cfmakeraw(&tty);
	
	if (tcsetattr(serial_port,  TCSANOW, &tty) != 0) {
		std::cerr << "Error " << errno << " from tcsetattr: " << strerror(errno) << std::endl;
	}
	
	ioctl(serial_port, TIOCSRS485, SER_RS485_ENABLED);
	
}

//List all available ports
std::vector<std::string> getAvailPorts() {
	std::vector<std::string> usbPorts;
	DIR *dir;
	struct dirent *ent;
	
	if ((dir = opendir("/dev")) != nullptr) {
		while ((ent = readdir(dir)) != nullptr) {
			if (ent->d_name && strncmp(ent->d_name, "ttyUSB", 6) == 0) {
				std::string portPath = "/dev/";
				portPath += ent->d_name;
				usbPorts.push_back(portPath);
			}
		}
		closedir(dir);
	} else {
		std::cerr << "Error opening /dev directory." << std::endl;
	}
	return usbPorts;
}

//Check if port is already opened or not
bool isPortOpen(const std::string& portPath) {
	int fd = open(portPath.c_str(), O_RDWR | O_NOCTTY);
	
	if (fd != -1) {
		close(fd);
		//std::cout << "Port can be opened" << std::endl;
		return true;
	} else {
		//std::cout << "Port already in use" << std::endl;
		return false;
	}
}

//Split string function again
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

//Convert from std::string to ascii values the motor expects
char* toAscii(std::string input) {
	int n = 0;
	//std::cout << input << std::endl;
	static char buf[256];
	memset(&buf, '\0', sizeof(buf));
	std::string output;
	for (int i = 0; i < input.length(); i += 2) {
		n = n * 10 + ((input[i] + input[i+1]) - '0');
		//n = input[i] + input[i+1];// - '0';
		char val(n);
		output += val;
		//printf("%d ", val);
		buf[(int)i/2] = val;
		//printf("%d\n", (int)i/2);
		n = 0;
	}
	//printf("\n");
	//printf("%s\n", buf);
	return buf;
}

std::string toAsciiBuff(std::string input) {
	std::string out;
	for (int i = 0; i < input.length(); ++i) {
		int val = (int)input[i];
		out += (char) val;
	}
	return out;
}
