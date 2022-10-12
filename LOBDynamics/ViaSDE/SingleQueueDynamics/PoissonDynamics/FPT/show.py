import matplotlib.pyplot as plt
import pandas as pd
data = pd.read_csv("./SingleQueueDynamics_out",header=None)
data = data.groupby(0)
a = data.mean()
b = data.std()
fig,ax = plt.subplots()
ax.plot(a.index,a[1])
plt.savefig("result")