from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import train_test_split
import pandas as pd

df = pd.read_csv('C:/Users/user/PycharmProjects/deepLearning/data/PimaIndiansDiabetes.csv')
print(df.head())
print(df.columns)

# column names
df_X= df.loc[:, df.columns!= 'diabetes']
df_y= df['diabetes']

# Split the data into training/testing sets
train_X, test_X, train_y, test_y= \
    train_test_split(df_X, df_y, test_size=0.3,\
                     random_state=1234)
best_acc=0
best_n_estimators = 0
best_max_features = 0

for i in (100,200,300,400,500):
    print(f'n_estimators = {i}')
    for j in (1,2,3,4,5):
        print(f'max_features = {j}')
        model = RandomForestClassifier(n_estimators=i, max_features=j, random_state=1234)
        # Train the model using the training sets
        model.fit(train_X, train_y)
        train_acc = model.score(train_X, train_y)
        test_acc = model.score(test_X, test_y)
        # performance evaluation
        print('Train accuracy :', train_acc)
        print('Test accuracy :', test_acc)
        if (test_acc > best_acc):
            best_n_estimators = i
            best_max_features = j
            best_acc = test_acc
        print()


print(f'Best Test accuracy : {best_acc}\nBest n_estimators : {best_n_estimators}'
      f'\nBest max_features : {best_max_features}')
