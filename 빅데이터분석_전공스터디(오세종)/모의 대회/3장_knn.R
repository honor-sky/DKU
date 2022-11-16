install.packages("pdp")
install.packages("gmodels")
library(pdp)
library(class)
library(gmodels)
head(pima)  

clean_data<-subset(pima,complete.cases(pima))#결측값 제거
summary(pima_n)
normalize<-function(x){
  return((x-min(x))/(max(x)-min(x)))
}

#데이터 정규화
pima_n<-as.data.frame(lapply(clean_data[,1:8], normalize))

#훈련/테스트 데이터 준비
pima_train<-pima_n[1:300,-9]
pima_test<-pima_n[301:392,-9]
pima_train_label<-factor(clean_data[1:300,9])
pima_test_label<-factor(clean_data[301:392,9])

#훈련
pima_test_pred<-knn(pima_train,pima_test,pima_train_label,k=19)

#성능평가
acc<-mean(pima_test_pred==pima_test_label) #약 83%
CrossTable(pima_test_label,pima_test_pred,prop.chisq=FALSE)


#성능개선
pima_n<-as.data.frame(scale(clean_data[,1:8]))#acc 더 떨어짐...
#k는 19일 때가 가장 좋음