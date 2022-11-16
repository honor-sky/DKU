install.packages("MASS")
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
#wine_train[,"quality"] <- as.factor(wine_train[,"quality"])
head(wine_train)
str(wine_train)

for(i in c(2:(ncol(wine_train)-1))){
  wine_train[,i]<-log(wine_train[,i])
}
wine_train <- wine_train[!is.infinite(rowSums(wine_train)),]
#feature selection
set.seed(100)
weights<-chi.squared(quality~.,wine_train)
square_subset<-cutoff.k(weights,10)#chi.squared 함수를 사용하여 feature 중요도 평가

##모델##
kfold <- function(classifier,folds,t) {
  acc <- c() #fold별acc 저장
  for(i in 1:5){
    ts.idx<-folds$subset[which(folds$which==i)]
    ds.train <- wine_train[-ts.idx,-1]
    ds.test <-  wine_train[ts.idx,-1]
    cl.train <- wine_train[-ts.idx,1]
    cl.test <- wine_train[ts.idx,1]
    
    if (classifier == 'svm') {
      model <- svm(ds.train, cl.train)
      pred <- round(predict(model, ds.test),0)
      acc[i] <- mean(pred==cl.test)
    }
    if (classifier == 'rf') {
      #model <- randomForest(ds.train, cl.train,ntree=500,mtry=3,nodesize = 1)  #samsize=4303 nodesize = 1
      model <- randomForest(ds.train, cl.train)
      pred <- round(predict(model, ds.test),0)
      acc[i] <- mean(pred==cl.test)
    }
    if(classifier == 'knn') {
      pred<-knn(ds.train,ds.test,cl.train,k=11,prob = FALSE)
      acc[i] <- mean(pred==cl.test)
    }
    if(classifier=='logi_reg') {
      model <- glm(quality~.,data=wine_train)
      pred <- round(predict(model, ds.test,type='response'),0)
      acc[i] <- mean(pred==cl.test)
    }
  }
  return(mean(acc))
}


result_mt<-c()
set.seed(100)
###svm,knn,rf###
folds<-cvFolds(nrow(wine_train), K=5)#5-fold
#result_mt<-kfold('rf',folds,400)
for(t in c(450:500)){
  result_mt[t-449]<-kfold('rf',folds,t)
}


for(i in c(3:12)){
  square_subset<-cutoff.k(weights,i)
  result_mt[i-2]<-kfold('rf',folds,square_subset)
}
    
for(t in c(398:403)){
  #result_mt[t-397]<-kfold('rf',folds,t)
  print(t)
} #ntree 실험 용


  
###xgboost###

folds<-cvFolds(nrow(wine_train), K=5)#5-fold
acc <- c() #폴드별 예측정확도
for(j in 1:5){
  
  ts.idx<-folds$subset[which(folds$which==j)]
  train.data<-xgb.DMatrix(data = as.matrix(wine_train[-ts.idx,-1]),
                          label = wine_train[-ts.idx,1])
  
  test.data<-xgb.DMatrix(data = as.matrix(wine_train[ts.idx,-1]),
                         label = wine_train[ts.idx,1])
  
  model <-xgboost(data=train.data,
                  max.depth=3, #트리의 최대 깊이 #0.8379444 최대값 도출
                  eta=1,       #학습률; (0,1]
                  nthread=2,   #스레드 개수(보통 코어의 수로 설정)
                  nrounds = 4, #최대 부스팅 반복 횟수
                  objective="reg:linear")
  
  pred<-round(predict(model, test.data),0)
  #pred<-as.numeric(pred>0.5)
  acc[j]<-mean(pred==wine_train[ts.idx,1])
}

mean(acc)



