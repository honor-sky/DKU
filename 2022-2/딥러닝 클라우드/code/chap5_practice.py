from sklearn.tree import DecisionTreeClassifier
from sklearn.ensemble import RandomForestClassifier
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

model_DecisionTree = DecisionTreeClassifier(random_state=1234)
model_RandomForest = RandomForestClassifier(random_state=1234)
model_SVM = svm.SVC()

model_DecisionTree.fit(train_X, train_y)
model_RandomForest.fit(train_X, train_y)
model_SVM.fit(train_X, train_y)

print('Train accuracy(DecisionTree) :', model_DecisionTree.score(train_X, train_y))
print('Test accuracy(DecisionTree) :', model_DecisionTree.score(test_X, test_y))
print()
print('Train accuracy(RandomForest) :', model_RandomForest.score(train_X, train_y))
print('Test accuracy(RandomForest) :', model_RandomForest.score(test_X, test_y))
print()
print('Train accuracy(SVM) :', model_SVM.score(train_X, train_y))
print('Test accuracy(SVM) :', model_SVM.score(test_X, test_y))
print()