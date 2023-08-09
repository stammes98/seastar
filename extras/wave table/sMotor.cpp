#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include "pubSysCls.h"

using namespace sFnd;
using namespace std;

#define CHANGE_NUMBER_SPACE	1000	//Change to numberspace after homing
#define TIME_TILL_TIMEOUT 	50000	//ms to wait for homing
#define ACC_LIM_RPM_PER_SEC	120.0
#define VEL_LIM_RPM		(60.0)
#define CNTS_PER_REV 		64000.0

extern "C" void setVel(int motor, double vel);
extern "C" void homeMotors();
extern "C" double getAngle(int motor);
extern "C" void cleanUp();

vector<string> comHubPorts;
SysManager* myMgr;

//Motor 0 = roll
//Motor 1 = pitch


//Home position = 1000 = 5.625 degrees
//End position = 43000 = 241.875 degrees
void setVel(int motor, double vel) {
	try {
		IPort &myPort = myMgr->Ports(0);
		INode &theNode = myPort.Nodes(motor);
		
		theNode.Motion.MoveWentDone();
		
		if (!theNode.Motion.VelocityReachedTarget()) {
			return;
		}
		
		double acSpeed = vel * 10;
		if (motor == 2) {
			acSpeed *= 5;
		}
		theNode.Motion.MoveVelStart(acSpeed);
	} catch (mnErr& theErr) {
		printf("Caught error: addr=%d, err=0x%08x\nmsg=%s", theErr.TheAddr, theErr.ErrorCode, theErr.ErrorMsg);
	}
}

void homeMotors() {
	printf("Beginning homing sequence\n");
	//HOMING THE MOTOR
	size_t portCount = 0;
	
	myMgr = SysManager::Instance();
	
	try {
		SysManager::FindComHubPorts(comHubPorts);
		printf("Found %d SC Hubs\n", comHubPorts.size());
		
		for (portCount = 0; portCount < comHubPorts.size() && portCount < NET_CONTROLLER_MAX; ++portCount) {
			myMgr->ComHubPort(portCount, comHubPorts[portCount].c_str());
		}
		
		if (portCount > 0) {
			myMgr->PortsOpen(portCount);
			
			for (size_t i = 0; i < portCount; ++i) {
				IPort &myPort = myMgr->Ports(i);
				printf("\tPort[%d]: state=%d, nodes=%d\n", myPort.NetNumber(), myPort.OpenState(), myPort.NodeCount());
			}
		} else {
			printf("Unable to locate SC hub port. Did you remember to plug it in again Steve?\n\nPress any key to continue.");
			getchar();
			exit(-1);
		}
		
		for (size_t iPort = 0; iPort < portCount; ++iPort) {
			IPort &myPort = myMgr->Ports(iPort);
			for (unsigned iNode = 0; iNode < myPort.NodeCount(); ++iNode) {
				INode &theNode = myPort.Nodes(iNode);
				//Make sure the motor is off
				//theNode.EnableReq(false);
				//Print debug info
				printf("\t\tNode[%d]: type=%d\n", iNode, theNode.Info.NodeType());
				printf("\t\tuserID: %s\n", theNode.Info.UserID.Value());
				printf("\t\tFW version: %s\n", theNode.Info.FirmwareVersion.Value());
				printf("\t\tSerial #: %d\n", theNode.Info.SerialNumber.Value());
				printf("\t\tModel: %s\n", theNode.Info.Model.Value());
				
				//Clear alerts
				theNode.Status.AlertsClear();
				//Clear shutdowns and stops
				theNode.Motion.NodeStopClear();
				//Clear motion signals
				theNode.Motion.MoveWentDone();
				//Start the motor
				theNode.EnableReq(true);
				
				double timeout = myMgr->TimeStampMsec() + TIME_TILL_TIMEOUT;
				//Wait for it to ready
				while (!theNode.Motion.IsReady()) {
					if (myMgr->TimeStampMsec() > timeout) {
						printf("Timed out waiting for Node %d to enable\n", iNode);
						printf("Press any key to continue\n");
						getchar();
						exit(-2);
					}
				}
				
				//Check if motor has been homed or not
				if (theNode.Motion.Homing.HomingValid()) {
					if (theNode.Motion.Homing.WasHomed()) {
						printf("Node %d has already been homed, at position %f\n", iNode, theNode.Motion.PosnMeasured.Value());
						printf("Rehoming...\n");
					} else {
						printf("Node %d has not been homed, doing so now...\n", iNode);
					}
					
					theNode.Motion.Homing.Initiate();
					timeout = myMgr->TimeStampMsec() + TIME_TILL_TIMEOUT;
					while (!theNode.Motion.Homing.WasHomed()) {
						if (myMgr->TimeStampMsec() > timeout) {
							printf("Node did not complete homing. Make sure settings are properly set in ClearView and you gave it enough time.");
							printf("Press any key to continue.\n");
							getchar();
							exit(-2);
						}
					}
					theNode.Motion.PosnMeasured.Refresh();
					printf("Node completed homing, current position: %f\n", theNode.Motion.PosnMeasured.Value());
					printf("Soft limits now active\n");
					
					printf("Adjusting numberspace by %d\n", CHANGE_NUMBER_SPACE);
					theNode.Motion.AddToPosition(CHANGE_NUMBER_SPACE);
					
					theNode.Motion.Homing.SignalComplete();
					theNode.Motion.PosnMeasured.Refresh();
					
					printf("Numberspace changed, current position: %f\n", theNode.Motion.PosnMeasured.Value());
					theNode.Limits.PosnTrackingLimit = (64000 + 1000) * 2;
					//theNode.Limits.PosnTrackingLimit.Refresh();
					printf("New tracking limit: %d\n", theNode.Limits.PosnTrackingLimit.Value());
					printf("Applying motion limits\n");
					theNode.AccUnit(INode::RPM_PER_SEC);
					theNode.VelUnit(INode::RPM);
					theNode.Motion.AccLimit = ACC_LIM_RPM_PER_SEC;
					theNode.Motion.VelLimit = VEL_LIM_RPM;
					printf("Motor velocity limit:\t%f RPM\n", VEL_LIM_RPM);
					printf("Motor acceleration limit:\t%f RPM/S\n", ACC_LIM_RPM_PER_SEC);
					theNode.Info.PositioningResolution.Refresh();
					uint32_t posRes = theNode.Info.PositioningResolution.Value();
					printf("Motor positioning resolution: %d counts/rev\n", posRes);
				} else {
					printf("Node %d needs to have homing setup in ClearView. Node will not be homed.\n");
				}
			}
		}
		
		
	} catch (mnErr& theErr) {
		printf("Caught error during homing: addr=%d, err=0x%08x\nmsg=%s", theErr.TheAddr, theErr.ErrorCode, theErr.ErrorMsg);
		
		printf("Press any key to continue\n");
		getchar();
		exit(-1);
	}
}


double getAngle(int motor) {
	try {
		IPort &myPort = myMgr->Ports(0);
		
		INode &theNode = myPort.Nodes(motor);
		theNode.Motion.PosnMeasured.Refresh();
		
		double mSpace = theNode.Motion.PosnMeasured.Value();
		//printf("%f\n", mSpace);
		return ((mSpace / CNTS_PER_REV) * 360.0) - 5.625;
	} catch (mnErr& theErr) {
		printf("Caught read error: addr=%d, err=0x%08x\nmsg=%s", theErr.TheAddr, theErr.ErrorCode, theErr.ErrorMsg);
		return 0.0;
	}
}

void cleanUp() {
//CLEAN-UP
	printf("Cleaning up.\n");
	try {
		IPort &myPort = myMgr->Ports(0);
		for (size_t iNode = 0; iNode < myPort.NodeCount(); ++iNode) {
			printf("Disabling node %d\n", iNode);
			myPort.Nodes(iNode).EnableReq(false);
		}
	} catch (mnErr& theErr) {
		printf("Caught error during clean-up addr=%d, err=0x%08x\nmsg=%s", theErr.TheAddr, theErr.ErrorCode, theErr.ErrorMsg);
		
		printf("Press any key to continue\n");
		getchar();
		exit(-1);
	}
	
	myMgr->PortsClose();
	
}

