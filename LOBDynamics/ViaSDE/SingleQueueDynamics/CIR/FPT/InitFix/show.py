import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
import sys
N = int(sys.argv[1])
data = pd.read_csv("./SingleQueueDynamics_out",header=None)
data = data.groupby(0)
a = data.mean()[1]
b = data.std()[1]
fig,ax = plt.subplots(1,1,figsize=(5,5))
ax.errorbar( a.index, a[1]/a.index, yerr=b/np.sqrt(N), capsize=2,capthick=2)
ax.set_yscale("log")
ax.set_xscale("log")
plt.savefig("result")