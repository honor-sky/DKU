#등분산 검정
var_eq<-c()
for(i in c(2:18)){
#분산동질성(F-value) 검증 후, 적절한 var.equal 옵션을 사용해야 함
#TRUE -> two sample student's t-test
#FALSE -> welch's t-test
if(var.test(new_data[,i]~new_data$clas_re,data=new_data)$p.value>0.05){ #p-value가 0.05이상이면 분산 동일(TRUE)
var_eq<-TRUE}else{
var_eq<-FALSE
}
}
library(FSelector)
library(caret)
library(e1071)  # svm
library(randomForest)
library(class)
library(cvTools)
library(MASS)
library(tidyverse)
library(cluster)
source("D:/단국대학교/연구실/빅데이터안과진단기술/수행과제/Feature 합성/공부자료(신현석)/nni_tools.R")
vf_oct<-read.csv("D:/단국대학교/연구실/빅데이터안과진단기술/수행과제/clean_dataset/vf_oct_clean_210817.csv")
#feature selection(1차)
f1_select<-c("Avg_RNFL_Thickness_value","Avg_RNFL_Thickness_p_v","RNFL_S","RNFL_S_m_v",
"Avg_RNFL_Thickness_p","Zone4","Zone4_m_v","Avg_RNFL_Thickness_p_p",
"Zone4_p","Zone2","Zone2_m_v","RNFL_I","RNFL_I_m_v","Zone4_m_p","RNFL_S_p",
"RNFL_I_p","Minimum.GCL.IPL.Thickness","RNFL_I_m_p","Zone2_m_p","Zone2_p",
"RNFL_S_m_p","VFI","PSD","Average.GCL.IPL.Thickness","Zone1","Zone1_m_v",
"GHT","Vertical.C.D_value","Vertical.C.D_p_v","Rim.Area_m_v","MD","Rim.Area_value",
"Zone3","Zone3_m_v","Zone1_p","Zone1_m_p","Zone3_p","Vertical.C.D_p","Rim.Area_p",
"Average.C.D_value", "Average.C.D_p_v","Zone3_m_p","Average.C.D_p","Vertical.C.D_p_p",
"RNFL_T","RNFL_T_m_v","Zone6")
data1<-cbind(vf_oct[,3],vf_oct[,f1_select])
names(data1)[1]<-"cl"
data1<-data1[complete.cases(data1),] #결측값 제거
data1[,"RNFL_S"]<-as.numeric(data1[,"RNFL_S"])
data1[,"RNFL_S_p"]<-as.numeric(data1[,"RNFL_S_p"])
proc_data<-set.data(data1, idx_cl = 1)
head(proc_data)
#합성 feature
NNI <- get.NNI(proc_data, K=5) # NNI
WNI <- get.WNI(proc_data, K=5) # WNI
loc <- get.loc(proc_data)      #loc
rsum <- get.rowsum(proc_data)  # rsum
dist <- get.dist(proc_data)    # dist
#feature selection(2차)
newset <- scale(data.frame(NNI, WNI, loc, rsum))
f2_select<-c("Avg_RNFL_Thickness_value","Avg_RNFL_Thickness_p_v","RNFL_S",
"RNFL_S_m_v","Avg_RNFL_Thickness_p","Zone4","Zone4_m_v","Avg_RNFL_Thickness_p_p"