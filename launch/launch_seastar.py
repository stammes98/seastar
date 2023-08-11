from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
	return LaunchDescription([
		Node(
			package='motor_state_manager',
			executable='motor_state_manager',
			name='msm'
		),
		Node(
			package='ik_solver',
			executable='ik_solver',
			name='ik_solver'
		),
		Node(
			package='ik_tools',
			executable='ik_tools',
			name='ik_tools'
		),
		Node(
			package='bluespace_ai_xsens_mti_driver',
			executable='xsens_mti_node',
			name='xsens'
		),
		Node(
			package='solar_ephemeris',
			executable='solar_ephemeris',
			name='solar_ephemeris'
		),
		Node(
			package='robot_localization',
			executable='ekf_node',
			name='filter'
		),
		Node(
			package='sunspotter',
			executable='sunspotter',
			name='sunspotter'
		),
		Node(
			package='head_chef',
			executable='head_chef',
			name='head_chef'
		),
	])
