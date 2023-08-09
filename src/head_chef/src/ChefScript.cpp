#include "ChefScript.h"
#include "head_chef.h"

ChefScript::ChefScript() {

}

ChefScript::ChefScript(std::string scriptPath) {
	loadScript(scriptPath);
}

/*
HomeAll = 0,		//HOAL
HomeOne = 1,		//HOON
FindSun = 2,		//FISU
FindStaySun = 3,	//FSSU
TrackSun = 4,		//TRSU
CircleSun = 5,		//CRSU
SetSunAzOff = 6,	//SUAO
SetSunAltOff = 7,	//SUEO
SetAzTarg = 8,		//SATG
SetAltTarg = 9,		//SETG
SetStokeTarg = 10,	//SSTG
SetSunStoke = 11,	//SSSU
FindTarg = 12,		//FTRG
FindStayTarg = 13,	//FSTG
CirlceTarg = 14,	//CRTG
ArcStart = 15,		//ARCS
ArcEnd = 16,		//ARCE
ArcSun = 17,		//ARSU
ArcTarg = 18,		//ARTG
Goto = 19,		//GOTO
Noop = 20		//NOOP
*/
void ChefScript::execNextLine() {
	if (execLine >= comms_.size()) {
		printf("End of script reached. Ending execution.\n");
		isDone = true;
		return;
	}

	ChefCommand curComm = comms_.at(execLine);
	Command c = curComm.comm_;
	double p = curComm.param_;
	
	printf("Running line %d: %d - %f\n", execLine, (int) c, p);
	
	execLine++;
	switch (c) {
		case HomeAll:
			printf("Calling home all routine for motors\n");
			chef_->homeAll();
			break;
		case HomeOne:
			{
			int hm = (int) p;
			printf("Calling home routine for motor %d\n", hm);
			printf("For now that's a lie and I'm lazy... Homing all motors...\n");
			chef_->homeAll();
			break;
			}
		case FindSun:
			printf("Finding sun\n");
			chef_->findSun();
			break;
		case FindStaySun:
			printf("Finding and staying with sun for %fs\n", p);
			chef_->findSunFor(p);
			break;
		case TrackSun:
			printf("Tracking sun for %fs\n", p);
			chef_->trackSunFor(p);
			break;
		case CircleSun:
			printf("Drawing loop around sun of radius %f\n", p);
			chef_->loopSun(p);
			break;
		case SetSunAzOff:
			printf("Setting sun azimuth offset to %f\n", p);
			chef_->setSolarAzOff(p);
			break;
		case SetSunAltOff:
			printf("Setting sun elevation offset to %f\n", p);
			chef_->setSolarAltOff(p);
			break;
		case SetAzTarg:
			printf("Setting secondary target azimuth to %f\n", p);
			chef_->setSTargAz(p);
			break;
		case SetAltTarg:
			printf("Setting secondary target elevation to %f\n", p);
			chef_->setSTargAlt(p);
			break;
		case SetStokeTarg:
			printf("Setting secondary target stokes angle to %f\n", p);
			chef_->setSTargPol(p);
			break;
		case SetSunStoke:
			printf("Setting solar stokes angle to %f\n", p);
			chef_->setSolarPolar(p);
			break;
		case FindTarg:
			printf("Moving to secondary target\n");
			chef_->findTarg();
			break;
		case FindStayTarg:
			printf("Moving to secondary target and staying for %fs\n", p);
			chef_->findStayTarg(p);
			break;
		case CircleTarg:
			printf("Circling target with radius of %f\n", p);
			chef_->loopTarg(p);
			break;
		case ArcStart:
			printf("Setting arc start angle to %f\n", p);
			chef_->setArcStart(p);
			break;
		case ArcEnd:
			printf("Setting arcend angle to %f\n", p);
			chef_->setArcEnd(p);
			break;
		case ArcSun:
			printf("Drawing arc around sun\n");
			chef_->arcSun(p);
			break;
		case ArcTarg:
			printf("Drawing arc around target\n");
			chef_->arcTarg(p);
			break;
		case Goto:
			{
			int newLine = (int) p;
			execLine = newLine;
			chef_->mode = WaitForComm;
			chef_->doneWithCommand = true;
			printf("GOTO called, jumping to %d\n", execLine);
			break;
			}
		case Noop:
			printf("No opping\n");
			break;
	}
	//execNextLine();
	
}

void ChefScript::hireChef(HeadChef* chef) {
	chef_ = chef;
}

void ChefScript::loadScript(std::string scriptPath) {
	std::string filePath = std::string(std::filesystem::current_path().c_str()) + scriptPath;
	printf("Loading script from %s\n", filePath.c_str());
	
	std::ifstream infile(filePath);
	std::string line;
	
	bool validScript = true;
	
	int l = 1;
	while (std::getline(infile, line)) {
		//std::cout << line << std::endl;
		bool goodLine = isValidCommand(line);
		validScript &= goodLine;
		if (!goodLine) {
			printf("ERROR: Line %d\n", l);
			break;
		}
		++l;

		
	}
	
	if (validScript) {
		std::cout << "Script loaded successfully\n";
	} else {
		std::cout << "Script did not load successfully\n";
		exit(-1);
	}
	
	for (ChefCommand c : comms_) {
		std::cout << c.comm_ << ", " << c.param_ << std::endl;
	}
	
	//execNextLine();
	
	
}

bool ChefScript::isValidCommand(std::string inLine) {
	std::string comm = inLine.substr(0, 4);
	size_t len = inLine.length();
	//std::cout << len << std::endl;
	std::string rest = inLine.substr(4, len);
	//std::cout << comm << "," << rest << std::endl;
	
	bool hasParam = (len == 4) ? false : true;
	//std::cout << hasParam << std::endl;
	for (int i = 0; i < 20; ++i) {
		if (CommNames[i] == comm) {
			//printf("Found command in list. Checking if it needs parameters / has parameters\n");
			if (hasParam == CommHasParam[i]) {
				//printf("Input command parameter and requested parameter match\n");
				if (hasParam) {
					comms_.push_back(ChefCommand(static_cast<Command>(i), std::stod(rest)));
				} else {
					comms_.push_back(ChefCommand(static_cast<Command>(i)));
				}
				return true;
			} 
			return false;
		}
	}
	return false;
}


