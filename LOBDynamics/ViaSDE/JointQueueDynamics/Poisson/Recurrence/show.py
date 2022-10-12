import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns
data = pd.read_csv("./SingleQueueDynamics_out",header=None)
plt.figure()
sns.histplot(data[0])
plt.savefig("result")