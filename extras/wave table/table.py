import pysMotor as pys
import time

print("Starting program")
pys.home()

pys.setVel(0, 15)
while (True):
	pass
'''
vDir = 2
wSpeed = 2

sleepTime = 5

pys.setVel(1, vDir * wSpeed)
time.sleep(int(sleepTime/2))

while (True):
	vDir *= -1
	pys.setVel(1, vDir * wSpeed)
	print("Switching direction")
	time.sleep(sleepTime)
'''
#time.sleep(100)
