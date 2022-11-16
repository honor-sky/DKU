#1
ds<-state.x77
ds[2,3]<-NA;ds[3,1]<-NA;ds[2,4]<-NA;ds[4,3]<-NA

colSums(is.na(ds))#01
ds[!complete.cases(ds),]#02
sum(rowSums(is.na(ds)>0))#03
ds.new<-ds[complete.cases(ds),]#04
ds.new

#2
st<-state.x77

boxplot(st)$out#01 #박스 그림 그리기

val_out<-boxplot(st)$out#02
st[st%in%val_out]<-NA
st

st2<-st[complete.cases(st),]#03
st2

#3
AQ<-airquality#01
colSums(is.na(AQ))#02
rowSums(is.na(AQ))#03
AQ[complete.cases(AQ),]#04

#05
AQ2<-AQ

AQ2[!complete.cases(AQ),"Ozone"]<-mean(AQ2[complete.cases(AQ),"Ozone"])#na가 있는 해당 열의 평균
AQ2[!complete.cases(AQ),"Solar.R"]<-mean(AQ2[complete.cases(AQ),"Solar.R"])
AQ2[!complete.cases(AQ),"Wind"]<-mean(AQ2[complete.cases(AQ),"Wind"])
AQ2[!complete.cases(AQ),"Temp"]<-mean(AQ2[complete.cases(AQ),"Temp"])
AQ2[!complete.cases(AQ),"Month"]<-mean(AQ2[complete.cases(AQ),"Month"])
AQ2[!complete.cases(AQ),"Day"]<-mean(AQ2[complete.cases(AQ),"Day"])
AQ2


#4
state.x77
state.x77[order(state.x77[,"Population"]),]#01
state.x77[order(state.x77[,"Income"],decreasing = T),]#02
head(state.x77[order(state.x77[,"Illiteracy"],decreasing = T),"Illiteracy"],10)#03

#5
mt.gear<-split(mtcars,mtcars$gear)#01
mt.gear
mt.gear$`4`#02
mt.gear.35<-rbind(mt.gear$`3`,mt.gear$`5`)#03
mt.gear.35
subset(mtcars,wt >=1.5&&wt<=3.0)#04

#6
install.packages("mlbench") #01
library("mlbench")
data("Glass")
myds<-Glass
myds#02
agg<-aggregate(myds[,-10],by=list(myds$Type),FUN=mean)
agg

#7
library(mlbench)#01
data("Ionosphere")
myds<-Ionosphere
agg<-aggregate(myds[,c("V3","V4","V5","V6","V7","V8","V9","V10")],by=list(myds$Class,myds$V1),FUN=sd)#02
agg


#8
idx<-sample(1:nrow(state.x77),size=20,replace = FALSE)
st20<-state.x77[idx,]
st.other<-state.x77[-st20,]
st20
st.other

#9
install.packages("sampling")
library(sampling)

iris.10<- strata(data = iris, stratanames = "Species", size = c(10, 10, 10),method = "srswor")
iris.10
# "srswor" : 비복원 단순 임의 추출
# "srswr" :  복원 단순 임의 추출
# "poisson" : 포아송 추출
# "systematic" : 계통 추출

#10
idx<-sample(1:nrow(iris),size=nrow(iris),replace = FALSE)
iris[idx,]

#11
x<-c("setosa","virginica","versicolor")
combn(x,2)

#12
x<-c("red","green","blue","black","yellow")
combn(x,3)

#13
class(iris)
dt<-data.frame(state.x77) #matrix는 subset이 작동 안 하므로 dataframe으로 바꿔준다

subset(dt,Area> dt["Alabama","Area"]&Area< dt["California","Area"],select = c("Population","Income","Area"))

#14
x<- read.csv("D:/단국대학교/2021-1/전공스터디(오세종)/subway.csv")#01
y<-read.csv("D:/단국대학교/2021-1/전공스터디(오세종)/subway_latlong.csv")
subway.tot<-merge(x,y,by.x="station",by.y="STATION_CD")

aggregate(subway.tot[,c("on_tot","off_tot")],by=list(subway.tot$STATION_NM,subway.tot$income_date),FUN=sum)#02

sb<-subset(subway.tot,grepl(2011,subway.tot[,"income_date"]))#03
sb
aggregate(sb[,c("on_tot","off_tot")],by=list(sb$STATION_NM),FUN=sum)

aggregate(sb[,c("on_tot","off_tot")],by=list(sb$LINE_NUM),FUN=sum)#04

#15
authors<-data.frame(
  surname=c("Twein","Venables","Tierney","Ripley","McNeil"),
  nationality=c("US","Australia","US","UK","Australia"),
  retired=c("yes",rep("no",4)))
                    
books<-data.frame(
  name=c("Jhon","Venables","Tierney","Ripley","Ripley","McNeil"),
  title=c("Exploratory Data Analysis",
          "Modern Applied Statistics...",
          "LIPS-STAT",
          "Spatial Statistics","Stochastic Simulation",
          "Interactive Data Analysis"),
  other.author=c(NA,"Ripley",NA,NA,NA,NA)) #01
                 

merge(authors,books,by.x=c("surname"),by.y=c("name"))#02
merge(authors,books,by.x=c("surname"),by.y=c("name"),all.x=T)#03
merge(authors,books,by.x=c("surname"),by.y=c("name"),all.y=T)#04
merge(authors,books,by.x=c("surname"),by.y=c("other.author"))#05
