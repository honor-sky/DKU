library(FSelector)
library(caret)
library(randomForest)
library(class)
library(cvTools)
library(MASS)
library(tidyverse)

###데이터 준비###
wine_train<-read.csv("D:/단국대학교/2021-1/전공스터디(오세종)/모의 대회/data/train.csv")
wine_test<-read.csv("D:/단국대학교/2021-1/전공스터디(오세종)/모의 대회/data/test.csv")
wine_train<-wine_train[,-1]
wine_test<-wine_test[,-1]

wine_train[,"type"] <- as.integer(as.factor(wine_train[,"type"]))-1
wine_test[,"type"] <- as.integer(as.factor(wine_test[,"type"]))-1
head(wine_train)
head(wine_test)


###파라미터 튜닝###
set.seed(123)
folds<-function(fold,n){ #5-fold 평균 구하기
  acc<-c()
  for(i in 1:5){
    
    ts.idx<-fold$subset[which(fold$which==i)]
    ds.train <- wine_train[-ts.idx,-1]
    ds.test <-  wine_train[ts.idx,-1]
    cl.train <- wine_train[-ts.idx,1]
    cl.test <- wine_train[ts.idx,1]
    
    model <- randomForest(ds.train, cl.train,mtry=3,ntree=n,nodesize=1) 
    #m=3(각 노드에서 랜덤하게 고려된 변수의 개수) n=451(몇개의 나무를 생성할지) -> 0.6767316  
    #ns=1 (각 노드에서 가져야할 값들의 최소값) -> 0.6767316 
    pred <- round(predict(model, ds.test),0)
    acc <- c(acc, mean(pred == cl.test))
 
  }
  return(mean(acc))
}

fold<-cvFolds(nrow(wine_train), K=5) #5-fold 설정
result <- c()

for(m in c(1:5)){     #mtry를 1~5 범위로 설정
  result<-c(result,m)                 
  for(n in c(390:420)){   #ntree 범위를 390~420 범위로 설정 후 확인
   result<-c(result,folds(fold,m,n))
   }
}

for(n in c(471:480)){     #mtry를 1~5 범위로 설정
  result<-c(result,folds(fold,n))

}

####feature 분석####





####오분류 데이터 분석####
