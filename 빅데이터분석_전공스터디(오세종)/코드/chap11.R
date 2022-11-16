#1
df<-data.frame(state.x77) #state.x77을 data.frame으로 만들어주기
par(mar=c(3,3,3,3))
plot(Illiteracy~Murder,data=df) #산점도 관측
model<- lm(Illiteracy~Murder,data=df) #회귀모델(회귀식) 구하기
model #Intercept가 상수(b), Murder가 가중치(W)
abline(model)

b<-coef(model)[1]
W<-coef(model)[2]
Murder<-c(0.5,1.0,1.5)
Illiteracy<-W*Murder + b
Illiteracy

#2
plot(Volume~Girth,data=trees) #산점도 관측
model<- lm(Volume~Girth,data=trees) #회귀모델(회귀식) 구하기
model #Intercept가 상수(b), Murder가 가중치(W)
abline(model)

b<-coef(model)[1]
W<-coef(model)[2]
Girth<-c(8.5,9.0,9.5)
Volume<-W*Girth + b
Volume

#3
plot(pressure~temperature,data=pressure) #산점도 관측
model<- lm(pressure~temperature,data=pressure) #회귀모델(회귀식) 구하기
model #Intercept가 상수(b), Murder가 가중치(W)
abline(model)

b<-coef(model)[1]
W<-coef(model)[2]
temperature<-c(65,95,155)
pressure<-W*temperature + b
pressure

#4-1
plot(trees,pch=16,col="blue") #변수간 관계 확인

mod1<-l(Volume~Girth+Height,data=trees)
mod1
summary(mod1)

#4-2
unknown<-trees[,c(1:2)]
pred<-predict(mod1,unknown) #예측
pred<-round(pred,1)
pred

#4-3
compare<-data.frame(pred,trees[,3],pred-trees[,3])
colnames(compare)<-c("예상","실제","오차차")
compare

#5-1
library(mlbench)
library(MASS)
data("BostonHousing")

BostonHousing

mod2<-lm(medv~crim+zn+indus+chas+nox+rm+age+dis+rad+tax+ptratio+b+lstat,data=BostonHousing)
mod2
summary(mod2)
income<-(3.646e+01)+(-1.080e-01*crim)+(4.642e-02*zn)+(2.056e-02*indus)+(2.687e+00*chas)+
  (-1.777e+01*nox)+(3.810e+00*rm)+(6.922e-04*age)+(-1.476e+00*dis)+(3.060e-01*rad)+
  (-1.233e-02*tax)+(-9.527e-01*ptratio)+(9.312e-03*b)+(-5.248e-01*lstat)

#5-2
mod3<-stepAIC(mod2)
mod3
summary(mod3)
income<-(36.341145)+(-0.108413*crim)+(0.0458452*zn)+(2.718716*chas)+
  (-17.376023*nox)+(3.810e+00*rm)+(1.492711*dis)+(3.060e-01*rad)+
  (-1.233e-02*tax)+(-9.527e-01*ptratio)+(9.312e-03*b)+(-5.248e-01*lstat)

#5-3
#mod2의 Adjusted R-squated   0.7338 
#mod3의 Adjusted R-squated   0.7348 ->설명력이 더 좋음

#6-1
#6-2
#6-3

#7-1
mydata<-read.csv("https://stats.idre.ucla.edu/stat/data/binary.csv")
mydata

mod.edu<-glm(admit~.,data=mydata)
summary(mod.edu)

#7-2
new.data<-mydata[,-1]
pred<-predict(mod.edu,new.data)
pred<-round(pred,0)
pred

compare<-data.frame(pred,mydata[,1])
colnames(compare)<-c("예측","실제")
compare

#7-3
acc<-mean(compare[1]==compare[,2])
acc
