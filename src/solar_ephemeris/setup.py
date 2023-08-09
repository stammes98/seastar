from setuptools import setup

package_name = 'solar_ephemeris'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Stephen Broccardo',
    maintainer_email='stephen.p.broccardo@nasa.gov',
    description='Publishes the solar ephemeris for SeaSTAR',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'solar_ephemeris = solar_ephemeris.solar_ephemeris:main'
        ],
    },
)
