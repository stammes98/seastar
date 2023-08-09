import sys

from seastar_interfaces.srv import PointMotors
from seastar_interfaces.msg import DesiredPointing, MotorCommand
import rclpy
from rclpy.node import Node

#Just used for debugging. Calls the IK solver, and then echos the response. 
class TestClient(Node):
	def __init__(self):
		super().__init__('ik_test_client')
		self.cli = self.create_client(PointMotors, 'ik_solver')
		while not self.cli.wait_for_service(timeout_sec=1.0):
			pass
		self.req = PointMotors.Request()
		
	def send_request(self, az, alt, pol):
		self.req.point.azimuth = az
		self.req.point.altitude = alt
		self.req.point.polarization = pol
		self.req.input_state.q1 = 0.0
		self.req.input_state.q2 = 0.0
		self.req.input_state.q3 = 0.0
		
		self.future = self.cli.call_async(self.req)
		rclpy.spin_until_future_complete(self, self.future)
		return self.future.result()
		
def main():
	rclpy.init()
	client = TestClient()
	response = client.send_request(float(sys.argv[1]), float(sys.argv[2]), float(sys.argv[3]))
	client.get_logger().info("Result: %f, %f, %f" % (response.command.q1, response.command.q2, response.command.q3))
	client.destroy_node()
	rclpy.shutdown()
	
if __name__ == '__main__':
	main()
