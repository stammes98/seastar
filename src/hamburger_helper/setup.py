import os
from setuptools import setup
from glob import glob
from setuptools import find_packages

package_name = 'hamburger_helper'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob(os.path.join('launch', '*launch.[pxy][yma]*'))),
    	(os.path.join('share', package_name), glob('*.py')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='seastar',
    maintainer_email='seastar@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'hamburger_helper = hamburger_helper.hamburger_helper:main'
        ],
    },
)
