import numpy as np
import matplotlib.pyplot as plt

P, I, D, inP, setpoint, err, dErr, integral, t = np.loadtxt("PID.csv", unpack=True, delimiter=',', skiprows=1)

plt.figure()
plt.plot(t, setpoint, label="Target value")
plt.plot(t, inP, label="Actual value")
plt.legend()
plt.show()
