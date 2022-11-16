from sklearn import datasets
from sklearn import svm
from sklearn.model_selection import KFold, cross_val_score
from sklearn.metrics import accuracy_score
import numpy as np

# Load the iris dataset
wine_X, wine_y= datasets.load_wine(return_X_y=True)

# Define fold
kf= KFold(n_splits=5, random_state=123, shuffle=True)

# 5 fold# Define learning model
model =  svm.SVC()
acc = np.zeros(5)
# 5 fold
i = 0
for train_index, test_index in kf.split(wine_X): #split 메소드 이용
    print("fold:", i)
    train_X, test_X= wine_X[train_index], wine_X[test_index]
    train_y, test_y=  wine_y[train_index], wine_y[test_index]

    # Train the model using the training sets
    model.fit(train_X, train_y)

    # Make predictions using the testing set
    pred_y= model.predict(test_X)
    # model evaluation: accuracy #############
    acc[i] = accuracy_score(test_y, pred_y)
    print('Accuracy : {0:3f}'.format(acc[i]))
    i += 1

print()
print("5 fold :", acc)
print("mean accuracy :", np.mean(acc))
print()

# Define learning model(Simple-Way)
model =  svm.SVC()
scores = cross_val_score(model, wine_X, wine_y, cv=5) # 자동 cross_val 메소드 이용(반복문 사용할 필요x)
print("fold acc", scores)
print("mean acc", np.mean(scores))