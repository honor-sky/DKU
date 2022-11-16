#4
std<-function(X){
  return((X-min(X))/(max(X)-min(X)))
}

mydata<-apply(rock[,],2,std)  #2는 margin
fit<-kmeans(x=mydata,centers=3)
library(cluster)
clusplot(rock,fit$cluster,color=TRUE,shade=TRUE,labels=2,lines=0)

#5
library(mlbench)
data("Sonar")
library(class)

tr.idx<-c()
for(i in 1:length(Sonar)){
  tr.idx<-append(tr.idx,2*i)
}


ds.tr<-Sonar[tr.idx,1:60] #훈련용
ds.ts<-Sonar[-tr.idx,1:60] #테스트용
cl.tr<-factor(Sonar[tr.idx,61]) #훈련용 그룹정보
cl.ts<-factor(Sonar[-tr.idx,61]) #테스트용 그룹정보

pred<-knn(ds.tr,ds.ts,cl.tr,k=3,prob=TRUE) #3-52%,5-48%,7-39%
pred
acc<-mean(pred==cl.ts)
acc

#6
install.packages("cvTools")
library(cvTools)
library(class)
data("Sonar")

k=5
folds<-cvFolds(nrow(Sonar),K=k)
acc<-c()
for(i in 1:k){ #k번 교차검증
  tr.idx<-folds$which==i
  ds.tr<-Sonar[tr.idx,1:60] #훈련용
  ds.ts<-Sonar[-tr.idx,1:60] #테스트용
  cl.tr<-factor(Sonar[tr.idx,61]) #훈련용 그룹정보
  cl.ts<-factor(Sonar[-tr.idx,61]) #테스트용 그룹정보
  
  pred<-knn(ds.tr,ds.ts,cl.tr,k=3)
  acc[i]<-mean(pred==cl.ts)
}
acc
mean(acc)

#7
install.packages("mlbench")
library(mlbench)
data("BreastCancer")

newdata<-BreastCancer[complete.cases(BreastCancer),] #NA 있는 행 제거
newdata$Class<-as.integer(newdata$Class) #Class를 정수형으로 바꿔줌

k=10
folds<-cvFolds(nrow(newdata),K=k)
acc<-c()

for(i in 1:k){ #k번 교차검증
  tr.idx<-folds$which==i
  ds.tr<-newdata[tr.idx,2:9] #훈련용
  ds.ts<-newdata[-tr.idx,2:9] #테스트용
  cl.tr<-factor(newdata[tr.idx,10]) #훈련용 그룹정보
  cl.ts<-factor(newdata[-tr.idx,10]) #테스트용 그룹정보
  
  pred<-knn(ds.tr,ds.ts,cl.tr,k=5)
  acc[i]<-mean(pred==cl.ts)
}
acc
mean(acc)
