install.packages("C50")
library(C50) #의사결정트리 패키지
library(gmodels) #crosstable 패키지

##데이터준비##
credit<-read.csv("D:/단국대학교/2021-1/전공스터디(오세종)/credit.csv",stringsAsFactors = TRUE)
#팩터타입의 범주형 문자 및 정수타입 데이터

set.seed(124)
train_sample<-sample(1000,900) #데이터 무작위 샘플링

credit_train<-credit[train_sample,]
credit_test<-credit[-train_sample,]

#훈련데이터와 테스트 대출 디폴트(채무불이행 여부)가 유사한 형태 보이면 훈련/데스트 치우침 없이 진행 가능
prop.table(table(credit_train$default))
prop.table(table(credit_test$default))

##모델설계##
credit_model<-C5.0(credit_train[,-17],credit_train$default)
summary(credit_model)

credit_pred<-predict(credit_model,credit_test)
CrossTable(credit_test$default,credit_pred, #실제결과와 예측결과 비교
           prop.chisq = FALSE, prop.c=FALSE,
           prop.r=FALSE, dnn=c("actual default","predicted default"))

##모델성능개선##
credit_boost10<-C5.0(credit_train[,-17],credit_train$default,trials=10)
summary(credit_boost10)

credit_pred<-predict(credit_boost10,credit_test)
CrossTable(credit_test$default,credit_pred, #실제결과와 예측결과 비교
           prop.chisq = FALSE, prop.c=FALSE,
           prop.r=FALSE, dnn=c("actual default","predicted default"))

##여러 오류유형에 패널티##
matrix_dimensions<-list(c("no","yes"),c("no","yes"))
names(matrix_dimensions)<-c("predicted","actual")
error_cost<-matrix(c(0,1,4,0),nrow=2,dimnames = matrix_dimensions) #패널티 행렬 생성

credit_cost<-C5.0(credit_train[,-17],credit_train$default,
                  cost=error_cost)
credit_cost_pred<-predict(credit_cost,credit_test)
CrossTable(credit_test$default,credit_cost_pred, #실제결과와 예측결과 비교
           prop.chisq = FALSE, prop.c=FALSE,
           prop.r=FALSE, dnn=c("actual default","predicted default"))
