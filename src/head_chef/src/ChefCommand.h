#ifndef CHEF_COM_H
#define CHEF_COM_H

#include <string>

enum Command {
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
	CircleTarg = 14,	//CRTG
	ArcStart = 15,		//ARCS
	ArcEnd = 16,		//ARCE
	ArcSun = 17,		//ARSU
	ArcTarg = 18,		//ARTG
	Goto = 19,		//GOTO
	Noop = 20		//NOOP
};


class ChefCommand {
public:
	
	ChefCommand();
	ChefCommand(Command comm);
	ChefCommand(Command comm, double param);
	Command comm_;
	double param_ = 0.0;
};


#endif
