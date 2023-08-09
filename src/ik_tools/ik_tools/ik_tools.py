import rclpy
import numpy as np
from rclpy.node import Node
from rclpy.qos import QoSProfile
from std_msgs.msg import String
from sensor_msgs.msg import JointState
from tf2_ros import TransformException
from tf2_ros.buffer import Buffer
from tf2_ros.transform_listener import TransformListener
from pykin.robots.single_arm import SingleArm
from pykin.kinematics.transform import Transform
from ik_helper import *
from scipy.spatial.transform import Rotation as R
from seastar_interfaces.msg import SkyEphemeris

camW = 640 #Used for scaling the solar tracking
camH = 480

class IkTools(Node):
	def __init__(self):
		super().__init__("ik_tools")
		
		self.tf_buffer = Buffer()
		self.tf_listener = TransformListener(self.tf_buffer, self)
		
		self.motor0listener = self.create_subscription(String, "/motors0", self.upMotor0, 10)
		self.motor1listener = self.create_subscription(String, "/motors1", self.upMotor1, 10)
		
		self.robot_state = np.array([0., 0., 0.])
		
		self.inJacPub = self.create_publisher(String, "/inv_jacobian", 10)
		self.robotPointPub = self.create_publisher(SkyEphemeris, "/robot_ephemeris", 10)
		
		self.sunX = 320
		self.sunY = 240
		
		self.sunSub = self.create_subscription(String, "/sunspot", self.updateSun, 10)
		
		self.filePath = '../../../../../../steve_summer_seastar_ws/urdf/seastar.urdf'
		self.robot = SingleArm(self.filePath, Transform(rot=[0, 0, 0], pos=[0, 0, 0]), has_gripper=False, gripper_name='Grippy')
		self.robot.setup_link_name("imu_link", "stokes_link")
		
		self.timer = self.create_timer(1/50.0, self.pub_stats)
		
	#Listen for the sunspot topic
	def updateSun(self, msg):
		x, y = msg.data.split(",")
		
		#tX = (((camW / 2) - sunSpots[0]) / camW);
		#tY = (((camH / 2) - sunSpots[1]) / camH);
		
		self.sunX = (((camW / 2) - float(x)) / camW)
		self.sunY = (((camH / 2) - float(y)) / camH)
		
	#Get the first pair of motor positions
	def upMotor0(self, msg):
		#print(msg.data)
		m1, m2, m3 = str(msg.data).split(",")
		self.robot_state[0] = self.encToAng(float(m1))
		self.robot_state[1] = self.encToAng(float(m2))
		self.robot_state[2] = self.encToAng(float(m3))
		
	#Get the second pair of motor positions
	def upMotor1(self, msg):
		m1, m2 = str(msg.data).split(",")
		self.robot_state[3] = self.encToAng(float(m1))
				
	#Publish the data we've computed
	def pub_stats(self):
		print(self.robot_state)
		#print(self.sunX, self.sunY)
		#Get the forward kinematics and pose given current sate
		fk = self.robot.forward_kin(np.deg2rad(self.robot_state))
		cur_state = list(fk.values())[-1].h_mat[:3, :3]
		
		r = R.from_matrix(cur_state)
		
		camRoll = r.as_euler("ZYX", degrees=True)[2]
		actualAz = r.as_euler("ZYX", degrees=True)[0] + 180.0 #Our definition is 0 south for some reason.
		actualAlt = -r.as_euler("ZYX", degrees=True)[1] #And negative, which you'd think we could remove both, but for some reason doesn't work
		
		print(r.as_euler("ZYX", degrees=True))
		#print(camRoll)
		print(actualAz, actualAlt)
		
		sunVec = np.array([self.sunX, -self.sunY, 0]) #Convert from camera space to desired rotation velocities
		#print(sunVec)
		newVec = np.concatenate((np.array([0.0, 0.0, 0.0]), r.apply(sunVec)))
		#print(newVec)
		
		Jinv = np.linalg.pinv(calc_jacobian(self.robot.desired_frames, fk, 3)) #Use the jacobian pseudo-inverse to convert from desired rotation velocities to desired motor velocities
		
		ik = Jinv @ newVec
		
		ik = 1 * ik #Here we can scale how much the robot responds but any more and it starts feeling like drawing circles
		
		#print(ik)
		
		msg2 = String()
		msg2.data = str(ik[0]) + "," + str(ik[1]) + "," + str(ik[2])
		self.inJacPub.publish(msg2)
		
		robotephemeris = SkyEphemeris()  # custom message type
		robotephemeris.elevation = float(actualAlt)
		robotephemeris.azimuth = float(actualAz)
		
		self.robotPointPub.publish(robotephemeris)
		
		#print(cur_state)

		
	def encToAng(self, enc):
		return (enc * 0.0018)
	
	def angToEnc(self, ang):
		return (ang * 555.555555555555555)

def main():
    rclpy.init()
    n = IkTools()
    rclpy.spin(n)
    rclpy.shutdown()


if __name__ == '__main__':
    main()
