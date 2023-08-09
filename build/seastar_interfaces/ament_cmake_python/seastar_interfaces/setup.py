from setuptools import find_packages
from setuptools import setup

setup(
    name='seastar_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('seastar_interfaces', 'seastar_interfaces.*')),
)
