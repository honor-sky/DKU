library(C50) #의사결정트리 패키지
library(gmodels) #crosstable 패키지
data(iris)

##데이터준비##
str(iris)

#iris는 정렬되어 있어서 무작위 샘플링 필요
set.seed(100)
train_sample<-sample(150,105) 

iris_train<-iris[train_sample,]
iris_test<-iris[-train_sample,]

prop.table(table(iris_train$Species))
prop.table(table(iris_test$Species))

##모델설계##
iris_model<-C5.0(iris_train[,-5],iris_train$Species)
summary(iris_model)

iris_pred<-predict(iris_model,iris_test)
CrossTable(iris_test$Species,iris_pred, #실제결과와 예측결과 비교
           prop.chisq = FALSE, prop.c=FALSE,
           prop.r=FALSE, dnn=c("actual Species","predicted Species"))
plot(iris_model)

#versicolor를 virginica로 예측한 경우 2가지를 제외하고는 모두 제대로 예측

##모델성능개선##
iris_boost10<-C5.0(iris_train[,-5],iris_train$Species,trials=10)
summary(iris_boost10) #모델은 모두 정확하게 분류

iris_pred<-predict(iris_boost10,iris_test)
CrossTable(iris_test$Species,iris_pred, #실제결과와 예측결과 비교
           prop.chisq = FALSE, prop.c=FALSE,
           prop.r=FALSE, dnn=c("actual Species","predicted Species"))

#테스트 데이터로 실험했을 땐, 오류가 성능개선 전과 동일
#모델의 문제보다는 오류 발생하는 데이터 두개가 분류가 까다로운 것으로 추정


##여러 오류유형에 패널티##
matrix_dimensions<-list(c("setosa","versicolor","virginica"),c("setosa","versicolor","virginica"))
names(matrix_dimensions)<-c("predicted","actual")
error_cost<-matrix(c(0,1,1,1,0,1,1,1,0),nrow=3,dimnames = matrix_dimensions) #패널티 행렬 생성

iris_cost<-C5.0(iris_train[,-5],iris_train$Species,
                  cost=error_cost)
iris_cost_pred<-predict(iris_cost,iris_test)
CrossTable(iris_test$Species,iris_pred, #실제결과와 예측결과 비교
           prop.chisq = FALSE, prop.c=FALSE,
           prop.r=FALSE, dnn=c("actual Species","predicted Species"))

#결과 동일(개선점 없음)
