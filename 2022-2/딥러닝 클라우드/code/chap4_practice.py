import pandas as pd
import numpy as np
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import train_test_split

#prepare dataset
data = \
pd.read_csv("C:/Users/user/PycharmProjects/deepLearning/data/BostonHousing.csv")
lstat = data['lstat']
medv = data['medv']

#data frame ro np.array
lstat = np.array(lstat).reshape(506,1)
medv = np.array(medv).reshape(506,1)

#Split the data into train/test sets
train_X, test_X, train_y, test_y = \
     train_test_split(lstat, medv, test_size=0.3, random_state=1234)
#Define model
model = LinearRegression()

#Train the model
model.fit(train_X,train_y)
print(model)
print('Cofficients: {0:.2f}, Intercept {1:.3f}'\
.format(model.coef_[0][0], model.intercept_[0]))

print(model.predict([[2.0]]))
print(model.predict([[3.0]]))
print(model.predict([[4.0]]))
print(model.predict([[5.0]]))

