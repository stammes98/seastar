#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/serial.h>
#include <string>
#include <chrono>

using namespace std::chrono;

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

int main() {
	int serial_port = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_SYNC);
	
	if (serial_port < 0) {
		printf("Error %i from open: %s\n", errno, strerror(errno));
	}
	
	struct termios tty;
	if (tcgetattr(serial_port, &tty) != 0) {
		printf("Error %i from tcgetattr: %s\n", errno, strerror(errno));
	}
	
	cfsetispeed(&tty, B57600);
	cfsetospeed(&tty, B57600);
	
	tty.c_cflag &= ~PARENB; 	//Clear parity bit, disabling parity 
	tty.c_cflag &= ~CSTOPB; 	//Clear stop field, only use one stop bit
	tty.c_cflag &= ~CSIZE;		//Clear the mask for setting data size
	tty.c_cflag |= CS8;		//Set 8 bits per byte
	tty.c_cflag &= ~CRTSCTS;	//Disable RTS/CTS hardware flow control
	tty.c_cflag |= CREAD | CLOCAL;	//Turn on READ & ignore ctrl lines
	
	tty.c_lflag &= ~ICANON;
	tty.c_lflag &= ~ECHO; 		//Disable echo
	tty.c_lflag &= ~ECHOE; 		//Disable erasure
	tty.c_lflag &= ~ECHONL;		//Disable new-line echo
	tty.c_lflag &= ~IEXTEN;		//
	tty.c_lflag &= ~ISIG;		//Disable interrupt from INTR, QUIT and SUSP
	
	tty.c_iflag &= ~(IXON | IXOFF | IXANY);				//Disable software flow control
	tty.c_iflag &= ~(INLCR | ICRNL | IUCLC | IGNCR | INPCK); 	//Disable special handling of recieved bytes
	
	tty.c_oflag &= ~OPOST; 		//Disable special interpretation of output bytes
	tty.c_oflag &= ~ONLCR; 		//Disable conversion of newline to carrige return
	
	tty.c_cc[VMIN] = 0;
	tty.c_cc[VTIME] = 5;
	//tty.c_cc[VEOL] = 0;
	//tty.c_cc[VEOL2] = 0;
	//tty.c_cc[VEOF] = 0x0D;
	
	cfmakeraw(&tty);
	
	if (tcsetattr(serial_port, TCSANOW, &tty) != 0) {
		printf("Error %i from tcsetattr: %s\n", errno, strerror(errno));
	}
	
	int RTS_flag, DTR_flag;
	
	RTS_flag = TIOCM_RTS;
	DTR_flag = TIOCM_DTR;
	
	ioctl(serial_port, TIOCSRS485, SER_RS485_ENABLED);

	
	std::string inString;

	int i = 0;
	int j = 0;

	while (true) {
		std::getline(std::cin, inString);

		
		/*
		if (j % 2 == 0) {
			inString = "0VE1\r";		
		} else {
			inString = "0IP\r";		
		}
		++j;
		*/
		

		int n = 0;
		int spot = 0;
		int n_written = 0;
		//std::cout << inString << std::endl;
		
		//inString.push_back('\r');
		
		//const char* msg = toAsciiBuff(inString).c_str();
		//printf("%s\n", msg);
		const char* msg = inString.c_str();
		//printf("%x\n", inString.c_str());
		
		//write(serial_port, "\x30\x56\x45\x35\x13", 5); 
		
		for (int i = 0; i < inString.length(); ++i) {
			char val[1] = {(char) inString[i]};
			write(serial_port, val, 1);
		}
		write(serial_port, "\r", 1);
		
		//write(serial_port, msg, sizeof(msg));
		//tcdrain(serial_port);

		char read_buf[256];
		char buf = '\0';
		memset(&read_buf, '\0', sizeof(read_buf));
		
		read(serial_port, &read_buf, sizeof(read_buf));
		
		/**
		do {
			n = read(serial_port, &buf, 1);
			sprintf(&read_buf[spot], "%c", buf);
			spot += n;
		} while (buf != '\r' && n > 0);
		**/
		//read(serial_port, &read_buf, sizeof(read_buf));
		
		std::cout << read_buf << std::endl;		
		
		//printf("%s\n\n", toAscii(read_buf));
		//printf("%s\n\n", acRes);
		//printf("%s\n\n", read_buf);
		
	}
	
	
	close(serial_port);
	
	return 0;
}
