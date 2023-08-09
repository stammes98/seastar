import numpy as np
from ctypes import *
from math import sin, cos, pi
import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile
from geometry_msgs.msg import Quaternion
from sensor_msgs.msg import JointState
from tf2_ros import TransformBroadcaster, TransformStamped
import os
from ament_index_python.packages import get_package_share_directory

#extern "C" void goToAngle(int motor, double angle);
#extern "C" void homeMotors();
#extern "C" double getAngle(int motor);
#extern "C" void cleanUp();

soName = 'pyMotor.so'
soPath = os.path.join(get_package_share_directory("pysp"), soName)
lib = cdll.LoadLibrary(soPath)

#lib = cdll.LoadLibrary("./pyMotor.so")
lib.setVel.argtypes = [c_int, c_double]
lib.getAngle.argtypes = [c_int]
lib.getAngle.restype = c_double

def setVel(motor, vel):
	lib.setVel(int(motor), float(vel))
	
def home():
	lib.homeMotors()
	
def getAngle(motor):
	a = c_double
	a = lib.getAngle(int(motor))
	return a
	
def cleanUp():
	try:
		lib.cleanUp()
	except:
		pass
	
