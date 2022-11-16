import matplotlib.pyplot as plt
import numpy as np

x = np.arange(12)
month = ['1월', '2월', '3월','4월','5월','6월','7월','8월','9월','10월','11월','12월']
values = [5,7,10,13,15,20,25,2,24,20,16,8]

plt.title('월평균 기온')
plt.xlabel('month')
plt.ylabel('temp')
plt.bar(x, values)
plt.xticks(x, month)

plt.show()