import numpy as np

#Calculates pose error just in terms of orientation, position error is set to zero
def calc_pose_error(tar_pose, cur_pose, EPS):
	pos_err = np.zeros((1, 3)) #We don't care where the head ends up, just where it points
	rot_err = np.dot(cur_pose[:3, :3].T, tar_pose[:3, :3]) #No idea how these two lines work
	w_err = np.dot(cur_pose[:3, :3], rot_to_omega(rot_err, EPS)) #Shamelessly borrowed from pykin because it just works
	return np.vstack((pos_err.T, w_err))

#Not really sure what this function does, but it was used in pykin, so we "borrow" it
def rot_to_omega(R, EPS):
	el = np.array([[R[2,1] - R[1,2]], [R[0, 2] - R[2, 0]], [R[1, 0] - R[0, 1]]])
	norm_el = np.linalg.norm(el)
	if norm_el > EPS:
		w = np.dot(np.arctan2(norm_el, np.trace(R) - 1) / norm_el, el)
	elif R[0, 0] > 0 and R[1, 1] > 0 and R[2, 2] > 0:
		w = np.zeros((3, 1))
	else:
		w = np.dot(np.pi / 2, np.array([[R[0, 0] + 1], [R[1, 1] + 1], [R[2, 2] + 1]]))
	return w

#From pykin as well, calculates for revolute joints
def calc_jacobian(frames, fk, jsize):
	target_position = list(fk.values())[-1].pos
	J = np.zeros((6, jsize))
	n = 0
	for frame in frames:
		if frame.joint.dtype == 'revolute':
			n += 1
			w = np.dot(fk[frame.link.name].h_mat[:3, :3], frame.joint.axis)
			v = np.cross(w, target_position - fk[frame.link.name].pos)
			J[:, n-1] = np.hstack((v, w))
	return J
