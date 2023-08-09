import numpy as np
import matplotlib.pyplot as plt

P, I, D, inP, setpoint, err, dErr, integral, t = np.loadtxt("PID.csv", unpack=True, delimiter=',', skiprows=1)

fig, ax = plt.subplots()
ax.plot(t, setpoint, color='b', label='setpoint')
ax.plot(t, inP, color='r', label='Actual')

ax2 = ax.twinx()
ax2.plot(t, integral, color='k', linestyle='--', label='Integral')
plt.show()
