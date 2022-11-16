from sklearn.tree import DecisionTreeClassifier
from sklearn.model_selection import train_test_split
import pandas as pd

# prepare the iris dataset
df = pd.read_csv('C:/Users/user/PycharmProjects/deepLearning/data/PimaIndiansDiabetes.csv')
# column names
df_X= df.loc[:, df.columns!= 'diabetes']
df_y= df['diabetes']

# Split the data into training/testing sets
train_X, test_X, train_y, test_y= \
    train_test_split(df_X, df_y, test_size=0.3,\
                     random_state=1234)

best_acc=0
best_max_depth = 0
best_min_samples_split = 0
# Define learning model (basic)
for i in range(3,21):
    print(f'max_depth = {i}')
    for j in range(2,11):
        print(f'min_samples_split = {j}')
        model = DecisionTreeClassifier(max_depth=i, min_samples_split=j, random_state=1234)
        # Train the model using the training sets
        model.fit(train_X, train_y)
        train_acc = model.score(train_X, train_y)
        test_acc = model.score(test_X, test_y)
        # performance evaluation
        print('Train accuracy :', train_acc)
        print('Test accuracy :', test_acc)
        if (test_acc > best_acc):
            best_max_depth = i
            best_min_samples_split = j
            best_acc = test_acc
        print()

print(f'Best Test accuracy : {best_acc}\nBest max_depth : {best_max_depth}'
      f'\nBest min_samples_split : {best_min_samples_split}')



