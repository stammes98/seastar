#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from sensor_msgs.msg import NavSatFix
from seastar_interfaces.msg import SkyEphemeris
from skyfield import api 

class SolarEphemeris(Node):
    def __init__(self):
        super().__init__('solar_ephemeris_calculator_node')
        
        self.ts = api.load.timescale()
        self.ephem = api.load_file('/home/seastar/de421.bsp')
        self.sun = self.ephem["Sun"]
        self.earth = self.ephem["Earth"]

        self.ephemeris_publisher_ = self.create_publisher(SkyEphemeris, '/solar_ephemeris', 10)
        self.gnss_subsciber_ = self.create_subscription(NavSatFix, '/gnss',
                self.gnss_callback, 10) 

        self.get_logger().info("Solar ephemeris calculator node has started")


    def gnss_callback(self, navsatfix: NavSatFix):

        location = api.wgs84.latlon(37.420, -122.057)
        #location = api.wgs84.latlon(float(navsatfix.latitude), float(navsatfix.longitude))
        sun_pos = (self.earth + location).at(self.ts.now()).observe(self.sun).apparent()
        sun_elevation, sun_azimuth, sun_distance = sun_pos.altaz()

        solarephemeris = SkyEphemeris()  # custom message type
        solarephemeris.elevation = float(sun_elevation.degrees)
        solarephemeris.azimuth = float(sun_azimuth.degrees)
        self.ephemeris_publisher_.publish(solarephemeris)

def main(args=None):
    rclpy.init(args=args)
    node = SolarEphemeris()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == '__main__':
    main()
