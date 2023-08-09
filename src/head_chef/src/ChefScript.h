#ifndef CHEF_SCRIPT_H
#define CHEF_SCRIPT_H

#include <string>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <sstream>
#include "ChefCommand.h"


class HeadChef;

class ChefScript {
public:
	ChefScript();
	ChefScript(std::string scriptPath);
	
	void hireChef(HeadChef* chef);
	void loadScript(std::string scriptPath);
	void execNextLine();
	
	bool isDone = false;
	
private:

	HeadChef* chef_;
	
	std::vector<ChefCommand> comms_;
	bool isValidCommand(std::string inLine);
	
	bool CommHasParam[21] = {false, true, false, true, true, true, true, true, true, true, true, true, false, true, true, true, true, true, true, true, false};
	std::string CommNames[21] = {"HOAL", "HOON", "FISU", "FSSU", "TRSU", "CRSU", "SUAO", "SUEO", "SATG", "SETG", "SSTG", "SSSU", "FTRG", "FSTG", "CRTG", "ARCS", "ARCE", "ARSU", "ARTG", "GOTO", "NOOP"};
	
	int execLine = 0;

};




#endif
