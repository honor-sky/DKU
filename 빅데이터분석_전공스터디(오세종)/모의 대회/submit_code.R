library(FSelector)
library(caret)
library(e1071)  # svm
library(randomForest)
library(class)
library(cvTools)
library(MASS)
library(tidyverse)
library(xgboost)

##데이터 준비##
wine_train<-read.csv("D:/단국대학교/2021-1/전공스터디(오세종)/모의 대회/data/train.csv")
wine_test<-read.csv("D:/단국대학교/2021-1/전공스터디(오세종)/모의 대회/data/test.csv")
wine_train<-wine_train[,-1]
wine_test<-wine_test[,-1]

wine_train[,"type"] <- as.integer(as.factor(wine_train[,"type"]))-1
wine_test[,"type"] <- as.integer(as.factor(wine_test[,"type"]))-1
head(wine_train)
head(wine_test)


weights<-chi.squared(quality~.,wine_train)
square_subset<-cutoff.k(weights,10)#chi.squared 함수를 사용하여 feature 중요도 평가

##모델##
set.seed(123)
model <- randomForest(wine_train[,-1], wine_train[,1],mtry=3,ntree=401,nodesize=1) 
pred <- round(predict(model, wine_test),0)
write.csv(pred,"D:/단국대학교/2021-1/전공스터디(오세종)/모의 대회/.csv")






