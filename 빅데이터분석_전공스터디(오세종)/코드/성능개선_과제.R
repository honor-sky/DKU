install.packages("xgboost")

#####과제1#####
library(xgboost)

#Load the data and remove Nas
install.packages("xgboost")
data("Sonar", package = "mlbench")
sona <- na.omit(Sonar)
head(sona)

#convert factor class into 0,1
sona$Class <- as.integer(sona$Class)-1
head(sona)

set.seed(123)
idx<-sample(nrow(sona), nrow(sona)*.2) #idx는 test data  idx
train.data<-xgb.DMatrix(data = as.matrix(sona[-idx,1:60]),
                                         label = sona$Class[-idx])
test.data<-xgb.DMatrix(data = as.matrix(sona[idx,1:60]),
                        label = sona$Class[idx])

model<-xgboost(data=train.data,
               max.depth=2, #트리의 최대 깊이
               eta=1,       #학습률; (0,1]
               nthread=2,   #스레드 개수(보통 코어의 수로 설정)
               nrounds = 2, #최대 부스팅 반복 횟수
               objective="binary:logistic") #사용할 분석 방법(필수)#이진분류를 위한 로지스틱 회귀

pred<-predict(model, test.data)
pred<-as.numeric(pred>0.5)

acc<-c()
acc<-mean(pred==sona$Class[idx])
acc



#####과제2#####

#Load the data and remove Nas
library(caret)

data("Vowel", package = "mlbench")
vo <- na.omit(Vowel)
head(vo)

#convert factor class into 0,1
vo$Class <- as.integer(vo$Class)
vo$V1 <- as.integer(vo$V1)
str(vo)
head(vo)

set.seed(123)
folds <- createFolds(vo$Class, k=10, list=TRUE, returnTrain = FALSE)
acc <- c() #폴드별 예측정확도
for(i in 1:10){
  tr.idx <- unlist(folds[i])
  train.data<-xgb.DMatrix(data = as.matrix(vo[-tr.idx,1:10]),
                          label = vo$Class[-tr.idx])
  test.data<-xgb.DMatrix(data = as.matrix(vo[tr.idx,1:10]),
                         label = vo$Class[tr.idx])
  
  model <-xgboost(data=train.data,
                     max.depth=2, #트리의 최대 깊이
                     eta=1,       #학습률; (0,1]
                     nthread=2,   #스레드 개수(보통 코어의 수로 설정)
                     nrounds = 2, #최대 부스팅 반복 횟수
                     objective="multi:softmax",
                  num_class=12)
  
  pred<-predict(model, test.data)
  acc[i] <- mean(pred==vo$Class[tr.idx]) 
}
mean(acc)


               