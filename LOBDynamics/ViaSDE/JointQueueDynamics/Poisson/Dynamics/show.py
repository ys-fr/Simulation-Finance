import matplotlib.pyplot as plt
import pandas as pd
data = pd.read_csv("./SingleQueueDynamics_out",header=None)
plt.figure()
plt.plot(data[2],data[1])
plt.savefig("result_volume")
plt.figure()
plt.plot(data[0],data[3])
plt.savefig("result_price")
