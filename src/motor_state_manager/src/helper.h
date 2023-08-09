#include <cstdio>
#include <cstring>
#include <stdio.h>
#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <linux/serial.h>
#include <errno.h>
#include <libconfig.h++>
#ifndef HELPER_H
#define HELPER_H




void sendCommand(int serial_port, std::string inString);
char* getResponse(int serial_port);
void setComSettings(int serial_port);
std::vector<std::string> getAvailPorts();
bool isPortOpen(const std::string& portPath);
std::vector<std::string> split(std::string s, std::string delimiter);
char* toAscii(std::string input);
std::string toAsciiBuff(std::string input);


#endif
