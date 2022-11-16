install.packages("ggplot2")
install.packages("treemap")
library(ggplot2)
library(treemap)


us<-data.frame(state.x77,state.division)

#1-01
us<-cbind(us,rownames(us))
names(us)[10]<-c("state")
treemap(us,index=c("state.division","state"),
        vSize="Population",
        vColor="Income",
        type="value")
#각 주의 인구수와 수입과의 관계성을 알 수 있다. 인구수가 많다고 해서반드시 수입이 높다는 것은 아님을 알 수 있다.
#지역구분에 따른 인구수와 수입도 알 수 있다.

#1-02
treemap(us,index=c("state.division","state"),
        vSize="HS.Grad",
        vColor="Murder",
        type="value")
#각 주의 고등학교 졸업률은 대강 비슷하고, 고등학교 졸업률과 범죄률 사이의 상관관계는 뚜렷하지 않은 것 같다.

#1-03
symbols(us$Income,us$Illiteracy,
        circles = us$Population,
        inches = 0.5,
        fg="white",
        bg="green",
        lwd=1.5,
        xlab="소득",
        ylab="문맹률",
        )
text(us$Income,us$Illiteracy,
     rownames(us),
     cex=0.6,
     col="brown")
#소득이 적을수록 문맹률이 높고, 대체적으로 인구수가 많은 주의 소득이 높게 나온다

#1-04
us
symbols(us$Illiteracy,us$Murder,
        circles = us$Area,
        inches = 0.5,
        fg="white",
        bg="green",
        lwd=1.5,
        xlab="소득",
        ylab="범죄률",
)
text(us$Illiteracy,us$Murder,
     rownames(us),
     cex=0.6,
     col="brown")
#소득이 높을수록 범죄률이 높다.또한 몇개의 주를 제외하고는 주의 면적과 범죄률 및 소득은 크게 상관없는 것 같다.(고르게 퍼져있다)

#2-01
Low<-subset(swiss,Education<=6)
Low[,"Education"]<-'Low'
Low<-cbind(Low,state=rownames(Low))

MID<-subset(swiss,Education>6&Education<13)
MID[,"Education"]<-'MID'
MID<-cbind(MID,state=rownames(MID))

HIGH<-subset(swiss,Education>=13)
HIGH[,"Education"]<-'HIGH'
HIGH<-cbind(HIGH,state=rownames(HIGH))

Group<-data.frame()
Group<-rbind(Group,Low)
Group<-rbind(Group,MID)
Group<-rbind(Group,HIGH)
Group

treemap(Group,index=c("Education","state"),
        vSize="Fertility",
        vColor="Agriculture",
        type="value")

#2-02
swiss<-cbind(swiss,state=rownames(swiss))
swiss

treemap(swiss,index=c("state"),
        vSize="Catholic",
        vColor="Examination",
        type="value")
 
    
#3
symbols(swiss$Fertility,swiss$Agriculture,
        circles = swiss$Education,
        inches = 0.5,
        fg="white",
        bg="green",
        lwd=1.5)
text(swiss$Fertility,swiss$Agriculture,
     rownames(swiss),
     cex=0.6,
     col="brown")

#4
symbols(trees$Girth,trees$Height,
        circles = trees$Volume,
        inches = 0.5,
        fg="white",
        bg="blue",
        lwd=1.5)
text(trees$Girth,trees$Height,
     1:nrow(trees),
     cex=0.8,
     col="red")

#5
HairEyeColor
mosaicplot(~Hair+Eye,data=HairEyeColor,color=TRUE)

#6
santa<-data.frame(belief=c('no belief','no belief','no belief','no belief','belief','belief','belief','belief','belief','belief',
                           'no belief','no belief','belief','belief', 'no belief','no belief'),
                  sibling=c('older brother','older sister','no older sibling',
                            'older sister','no older sibling','no older sibling','no older sibling',
                            'older sister','older brother', 'older sister','older brother',
                            'older sister','no older sibling','older sister','older brother','no older sibling'))
mosaicplot(~belief+sibling,data=santa,color=TRUE)
#산타 믿는 사람 별 손위형제여부

#7
ggplot(mtcars,aes(x=gear))+
  geom_bar()+
  xlab("기어의 수")+
  ylab("빈도수")

#8
ggplot(mtcars,aes(x=cyl))+
  geom_bar(fill="green")+
  xlab("실린더의 수")+
  ylab("빈도수")

#9
ggplot(mtcars,aes(x=mpg))+
  geom_histogram(binwidth = 5.0)

#10
ggplot(trees,aes(x=Girth))+
  geom_histogram(binwidth = 3.0,fill="steelblue",color="steelblue")+
  ggtitle("나무둘레에 따른 히스토그램")+
  xlab("나무둘레")+
  ylab("갯수")

#11
ggplot(mtcars,aes(x=mpg,y=wt,color=gear))+
  geom_point(size=3)+
  xlab("연비")+
  ylab("중량")

#12
ggplot(data=mtcars,aes(y=mpg,group=cyl,fill=cyl))+ 
  geom_boxplot()
#그룹으로 묶을 변수의 타입이 숫자인 경우, group= 을 사용 fill= 은 색 채울 때 사용

#13
year<-2015:2026
population<-c(51014,51245,51446,51635,51811,51973,52123,52261,52388,52504,52609,52704)
df<-data.frame(year,population)

ggplot(df,aes(x=year,y=population))+
  geom_line() #col="red" 안 해도 선그래프 검정으로 나옴(default의 문제 일수도)
  
#14
year<-c(201404,201501,201502,201503,201504,201601,201602,201603,201604,201701,201702,201703)
male<-c(73.9,73.1,74.4,74.2,73.5,73,74.2,74.5,73.8,73.1,74.5,74.2)
female<-c(51.4,50.5,52.4,52.4,51.9,50.9,52.6,52.7,52.2,51.5,53.2,53.1)

df<-data.frame(year,male)
df<-cbind(df,female)

ggplot(df,aes(x=year))+
  geom_line(aes(y=male))+
  geom_line(aes(y=female))

#15
library("Rtsne")
library("rgl")
library(car)
library("mgcv")
ds<-state.x77[,]

tsne_2<-Rtsne(ds,dims=2,perplexity=10) #랜덤으로 샘플링 되므로 실행마다 다른 산점도
df.tsne<-data.frame(tsne_2$Y)
ggplot(df.tsne,aes(x=X1,y=X2))+
  geom_point(size=2)

tsne_3<-Rtsne(ds,dims=3,perplexity=10)
df.tsne_3<-data.frame(tsne_3$Y)
scatter3d(x=df.tsne_3$X1,y=df.tsne_3$X2,z=df.tsne_3$X3)

