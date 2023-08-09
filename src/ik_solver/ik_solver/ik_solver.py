from seastar_interfaces.srv import PointMotors
from seastar_interfaces.msg import DesiredPointing, MotorCommand
import rclpy
from rclpy.node import Node

import numpy as np
from ik_helper import *
from pykin.robots.single_arm import SingleArm
from pykin.kinematics.transform import Transform
from math import sin, cos


class IKService(Node):
	def __init__(self):
		super().__init__("ik_solver")
		self.srv = self.create_service(PointMotors, "ik_solver", self.ik_callback)
		
		self.filePath = '../../../../../../steve_summer_seastar_ws/urdf/seastar.urdf'
		self.robot = SingleArm(self.filePath, Transform(rot=[0, 0, 0], pos=[0, 0, 0]), has_gripper=False, gripper_name='Grippy')
		self.robot.setup_link_name("imu_link", "stokes_link")
		
		
	#Handle the callback in a more readable format
		
	def ik_callback(self, request, response):
		inState = request.input_state
		desState = request.point
		
		print(inState.q1, inState.q2, inState.q3)
		print(desState.azimuth, desState.altitude, desState.polarization)

		targ_pose = self.sMat(desState.azimuth, desState.altitude)
		startPose = np.deg2rad(np.array([inState.q1, inState.q2, inState.q3]))


		goalPose = self.solve_ik(targ_pose, startPose)		
		
		
		
		response.command.q1 = goalPose[0]
		response.command.q2 = goalPose[1]
		response.command.q3 = goalPose[2]
		return response
		
	#actually do the IK
	#taken from pykin LM2 method
	def solve_ik(self, targ_pose, startPose):
		curPose = np.copy(startPose) #Pose of the robot in motor space
		fk = self.robot.forward_kin(startPose)
		cur_state = list(fk.values())[-1].h_mat
		
		wn_pos = 1 / 0.3
		wn_ang = 1 / (2 * np.pi)
		
		We = np.diag([wn_pos, wn_pos, wn_pos, wn_ang, wn_ang, wn_ang])
		Wn = np.eye(3)
		
		EPS = float(1e-12)
		DOF = 3
		
		err_pose = calc_pose_error(targ_pose, cur_state, EPS)
		err = np.linalg.norm(err_pose)
		
		iterator = 0
		max_iter = 1000 #Usually solves in about 30-40, any more and the time for a failed solve gets looooooooong
		lamb = 0.5
		didSolve = True
		while err > EPS:
			iterator += 1
			if iterator > max_iter:
				didSolve = False
				break
			J = calc_jacobian(self.robot.desired_frames, fk, DOF)
			dq = lamb * np.dot(np.linalg.pinv(J), err_pose)
			curPose = [curPose[i] + dq[i] for i in range(DOF)]
			fk = self.robot.forward_kin(curPose)
			cur_state = list(fk.values())[-1].h_mat
			err_pose = calc_pose_error(targ_pose, cur_state, EPS)
			err = np.linalg.norm(err_pose)
		endPose = np.array([float(curP) for curP in curPose])
		print(f"Iter: {iterator}\nErr: {err}")
		if (not didSolve):
			endPose = startPose #Don't freak the motors out if we couldn't solve
		return np.rad2deg(endPose)
			
		
		
		
	#Returns orientation / fake position of sun given input azimuth (theta) and elevation (phi) - assumes zero roll (polarization)
	def sMat(self, theta, phi):
		theta = np.deg2rad(theta+180.0)
		phi = -np.deg2rad(phi)
		return np.array([[cos(theta) * cos(phi), -sin(theta), cos(theta) * sin(phi), 0],
				[sin(theta) * cos(phi), cos(theta), sin(theta) * sin(phi), 0],
				[-sin(phi), 0, cos(phi), 0],
				[0, 0, 0, 1]])
				
		

def main():
    rclpy.init()
    serv = IKService()
    rclpy.spin(serv)
    rclpy.shutdown()


if __name__ == '__main__':
    main()
