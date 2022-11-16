###파라미터 튜닝###
set.seed(123)
folds<-function(fold,ns){ #5-fold 평균 구하기
acc<-c()
for(i in 1:5){
ts.idx<-fold$subset[which(fold$which==i)]
ds.train <- wine_train[-ts.idx,-1]
ds.test <-  wine_train[ts.idx,-1]
cl.train <- wine_train[-ts.idx,1]
cl.test <- wine_train[ts.idx,1]
model <- randomForest(ds.train, cl.train,mtry=3,ntree=401,nodesize=ns)
#m=3(각 노드에서 랜덤하게 고려된 변수의 개수) n=401(몇개의 나무를 생성할지) #ns=(각 노드에서 가져야할 값들의 최소값)
pred <- round(predict(model, ds.test),0)
acc <- c(acc, mean(pred == cl.test))
}
return(mean(acc))
}
fold<-cvFolds(nrow(wine_train), K=5) #5-fold 설정
result <- c()
for(mns in c(1:5)){     #mtry를 1~5 범위로 설정
result<-c(result,folds(fold,ns))
}
for(ns in c(1:5)){     #mtry를 1~5 범위로 설정
result<-c(result,folds(fold,ns))
}
result
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
#m=3(각 노드에서 랜덤하게 고려된 변수의 개수) n=401(몇개의 나무를 생성할지)->0.6679995
#ns=1 (각 노드에서 가져야할 값들의 최소값) -> 0.6745504
pred <- round(predict(model, ds.test),0)
acc <- c(acc, mean(pred == cl.test))
}
return(mean(acc))
}
fold<-cvFolds(nrow(wine_train), K=5) #5-fold 설정
result <- c()
result<-c(result,folds(fold,450))
result
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
#m=3(각 노드에서 랜덤하게 고려된 변수의 개수) n=401(몇개의 나무를 생성할지)->0.6679995
#ns=1 (각 노드에서 가져야할 값들의 최소값) -> 0.6745504
pred <- round(predict(model, ds.test),0)
acc <- c(acc, mean(pred == cl.test))
}
return(mean(acc))
}
fold<-cvFolds(nrow(wine_train), K=5) #5-fold 설정
result <- c()
result<-c(result,folds(fold,455))
result
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
model <- randomForest(ds.train, cl.train,m