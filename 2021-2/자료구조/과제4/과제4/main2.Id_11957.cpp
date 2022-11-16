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
model <- randomForest(ds.train, cl.train,mtry=3,ntree=401,nodes