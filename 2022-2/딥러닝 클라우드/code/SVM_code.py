from sklearn import svm
from sklearn.model_selection import train_test_split
import pandas as pd

df = pd.read_csv('C:/Users/user/PycharmProjects/deepLearning/data/PimaIndiansDiabetes.csv')
df_X= df.loc[:, df.columns!= 'diabetes']
df_y= df['diabetes']

# Split the data into training/testing sets
train_X, test_X, train_y, test_y= \
    train_test_split(df_X, df_y, test_size=0.3,\
                     random_state=1234)

# Define learning model (kernel)  ############
for i in ('linear','poly' , 'rbf' , 'sigmoid'):
    print(f'kernel = {i}')
    model = svm.SVC(kernel = i)
    # Train the model using the training sets
    model.fit(train_X, train_y)

    # performance evaluation
    print('Train accuracy :', model.score(train_X, train_y))
    print('Test accuracy :', model.score(test_X, test_y))
    print()
    #pred_y = model.predict(test_X)
    #confusion_matrix(test_y, pred_y)
