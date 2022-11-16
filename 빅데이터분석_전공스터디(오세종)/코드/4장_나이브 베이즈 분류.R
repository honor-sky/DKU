install.packages("tm")
install.packages("SnowballC")
install.packages("wordcloud")
install.packages("gmodels")
install.packages("Rcpp")
library(tm)
library(SnowballC)
library(wordcloud)
library(e1071)
library(gmodels)
library(Rcpp)
sms_raw<-read.csv("D:/단국대학교/2021-1/전공스터디(오세종)/sms_spam.csv",stringsAsFactors = FALSE)
str(sms_raw)
head(sms_raw)

sms_raw$type<-factor(sms_raw$type)
sms_raw$text<-iconv(enc2utf8(sms_raw$text),sub="byte") #encoding
sms_corpus<-VCorpus(VectorSource(sms_raw$text)) #텍스트문서 모음 생성

inspect(sms_corpus[1:2]) #첫 번째와 두 번째 메세지 요약
lapply(sms_corpus[1:12],as.character) #항목별로 함수 적용


sms_corpus_clean<-tm_map(sms_corpus,content_transformer(tolower)) #대->소 변환
sms_corpus_clean<-tm_map(sms_corpus_clean,removeNumbers) #숫자 제거
sms_corpus_clean<-tm_map(sms_corpus_clean,removeWords,stopwords()) #불용어 제거(but,or,and..)
sms_corpus_clean<-tm_map(sms_corpus_clean,removePunctuation) #구두점 제거                          
sms_corpus_clean<-tm_map(sms_corpus_clean,stemDocument) #형태소 분석
sms_corpus_clean<-tm_map(sms_corpus_clean,stripWhitespace) #추가여백 제거

as.character(sms_corpus[[1]]) #비교
as.character(sms_corpus_clean[[1]])

sms_dtm<-DocumentTermMatrix(sms_corpus_clean)

sms_dtm_train<-sms_dtm[1:4169,]
sms_dtm_test<-sms_dtm[4170:5559,]
sms_train_labels<-sms_raw[1:4169,]$type
sms_test_labels<-sms_raw[4170:5559,]$type

prop.table(table(sms_train_labels))
prop.table(table(sms_test_labels))

wordcloud(sms_corpus_clean, min.freq = 10, random.order=FALSE)

#스팸,햄 메세지 각각의 단어 구름
spam <- subset(sms_raw,type=="spam")#스팸 메세지 
ham <- subset(sms_raw, type=="ham")#햄 메세지
wordcloud(spam$text, max.words = 40, scale=c(3, 0.5))
wordcloud(ham$text, max.words = 40, scale=c(3, 0.5))

sms_freq_words<-findFreqTerms(sms_dtm_train,5)
sms_dtm_freq_train<-sms_dtm_train[,sms_freq_words]
sms_dtm_freq_test<-sms_dtm_test[,sms_freq_words]

convert_counts<-function(x){
  x<-ifelse(x>0,"Yes","No")
}

sms_train<-apply(sms_dtm_freq_train,MARGIN = 2,convert_counts)
sms_test<-apply(sms_dtm_freq_test,MARGIN = 2,convert_counts)

sms_classifier<-naiveBayes(sms_train,sms_train_labels)
sms_test_pred<-predict(sms_classifier,sms_test)
CrossTable(sms_test_pred,sms_test_labels,
           prop.chisq=FALSE,prop.c=FALSE,
           prop.r=FALSE,dnn=c('predicted','actual'))



sms_classifier2 <- naiveBayes(sms_train, sms_train_labels, laplace=1)
sms_test_pred2 <- predict(sms_classifier2, sms_test)
CrossTable(sms_test_pred2, sms_test_labels,
           prop.chisq = FALSE, prop.c=FALSE,
           prop.r=FALSE, dnn=c("predicted","actual"))
