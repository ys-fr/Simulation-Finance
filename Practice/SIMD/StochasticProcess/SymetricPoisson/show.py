import matplotlib.pyplot as plt
import pandas as pd
data = pd.read_csv("./SymPoisson_out",header=None)
plt.plot(data[0],data[1])
plt.savefig("result")