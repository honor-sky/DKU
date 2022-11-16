import pandas as pd  #1
import matplotlib.pyplot as plt
from matplotlib import font_manager, rc
import locale

#폰트 설정
font_path = "./malgun.ttf"
font_name =font_manager.FontProperties(fname=font_path).get_name()
rc('font',family=font_name)
plt.rcParams.update({'font.family':'Malgun Gothic','font.size':12})

####노선별 승차총승객수 분석######
pass_ = pd.read_csv("D:/단국대학교/2021-2/AI전공별 활용/서울시 버스노선별 정류장별 승하차 인원 정보 (1).csv", encoding='euc-kr') #2021년 정보
pass_=pass_[(pass_['노선번호']=='2016')|(pass_['노선번호']=='700')|(pass_['노선번호']=='7727')|(pass_['노선번호']=='273')|(pass_['노선번호']=='260')]
pass_ = pass_.sort_values(by=['사용일자']) #사용일자를 기준으로 정렬(1일~30일)
print(pass_)

#데이터 타입 변경
pass_ = pass_.astype({'사용일자': 'str'})
pass_ = pass_.astype({'승차총승객수': 'int16'})
print(pass_.dtypes)

#월별 이용 승객 수 저장할 데이터프레임 생성
pass_2016_mon=pd.DataFrame(index=['1101','1102','1103','1104','1105','1106','1107','1108','1109','1110','1111',
                                  '1112','1113','1114','1115','1116','1117','1118','1119','1120','1121','1121',
                                  '1121','1122','1123','1124','1125','1126','1127','1128','1129','1130'],columns=['2016','700','7727','273','260'])

#날짜 list
month_list=['20211101','20211102','20211103','20211104','20211105','20211106','20211107','20211108','20211109','20211110','20211111','20211112','20211113','20211114',
            '20211115','20211116','20211117','20211118','20211119','20211120','20211121','20211121','20211121',
            '20211122','20211123','20211124','20211125','20211126','20211127','20211128','20211129','20211130']

##노섭별로 날짜마다 총승객수 계산해 저장
for i in range (len(month_list)):
    each_month= pass_[pass_['사용일자'].str.contains(month_list[i], na=False, case=False)]
    sum = 0
    for j in range(len(each_month[(each_month['노선번호'] == '2016')])):
        try:
            sum += each_month[(each_month['노선번호'] == '2016')].iloc[j, 6]
        except KeyError:
           continue
        pass_2016_mon.iloc[i, 0] = sum
    sum = 0
    for j in range(len(each_month[(each_month['노선번호'] == '700')])):
        try:
            sum += each_month[(each_month['노선번호'] == '700')].iloc[j, 6]
        except KeyError:
            continue
        pass_2016_mon.iloc[i, 1] = sum
    sum = 0
    for j in range(len(each_month[(each_month['노선번호'] == '7727')])):
        try:
            sum += each_month[(each_month['노선번호'] == '7727')].iloc[j, 6]
        except KeyError:
            continue
        pass_2016_mon.iloc[i, 2] = sum
    sum = 0
    for j in range(len(each_month[(each_month['노선번호'] == '273')])):

        try:
            sum += each_month[(each_month['노선번호'] == '273')].iloc[j, 6]
        except KeyError:
            continue
        pass_2016_mon.iloc[i, 3] = sum
    sum = 0
    for j in range(len(each_month[(each_month['노선번호'] == '260')])):
        try:
            sum += each_month[(each_month['노선번호'] == '260')].iloc[j, 6]
        except KeyError:
            continue
        pass_2016_mon.iloc[i, 4] = sum

print(pass_2016_mon)

##시각화
plt.style.use('ggplot') #스타일 서식 지정
fig=plt.figure(figsize=(14,5))
ax=fig.add_subplot(1,1,1)

ax.plot(pass_2016_mon.index,pass_2016_mon['2016'],marker='o',markersize=5,markerfacecolor='green',color='olive',label='2016')
ax.plot(pass_2016_mon.index,pass_2016_mon['700'],marker='o',markersize=5,markerfacecolor='blue',color='skyblue',label='700')
ax.plot(pass_2016_mon.index,pass_2016_mon['7727'],marker='o',markersize=5,markerfacecolor='red',color='magenta',label='7727')
ax.plot(pass_2016_mon.index,pass_2016_mon['273'],marker='o',markersize=5,markerfacecolor='purple',color='purple',label='273')
ax.plot(pass_2016_mon.index,pass_2016_mon['260'],marker='o',markersize=5,markerfacecolor='black',color='black',label='260')
ax.set_title('11월 2016 승차총승객수')
ax.set_ylabel('승차총승객수',size=10)
ax.set_xlabel('날짜',size=10)
ax.legend(loc='best')
plt.show()


####노선별 주행거리 분석######
bus_dist=pd.read_csv("D:/단국대학교/2021-2/AI전공별 활용/서울시 시내버스 노선별 주행거리.csv")
bus_dist=bus_dist[(bus_dist['운행일자']==20180301)] #주행거리는 하루치만 사용
bus_dist = bus_dist[~bus_dist['노선'].str.contains("N", na=False, case=False)] #야간버스 제외
##2016버스와 주행거리 차이 많이 나는 데이터 제외
bus_dist = bus_dist[bus_dist['운행거리(Km)'].str.contains("5,", na=False, case=False)]
bus_dist = bus_dist[~bus_dist['운행거리(Km)'].str.contains("5,9", na=False, case=False)]
bus_dist = bus_dist[~bus_dist['운행거리(Km)'].str.contains("5,8", na=False, case=False)]
bus_dist = bus_dist[~bus_dist['운행거리(Km)'].str.contains("5,0", na=False, case=False)]
bus_dist = bus_dist[~bus_dist['운행거리(Km)'].str.contains("5,7", na=False, case=False)]
bus_dist = bus_dist[~bus_dist['운행거리(Km)'].str.contains("5,1", na=False, case=False)]
bus_dist = bus_dist[~bus_dist['운행거리(Km)'].str.contains("5,6", na=False, case=False)]
bus_dist = bus_dist.sort_values(by=['노선'])
print(bus_dist)

locale.setlocale(locale.LC_ALL, 'en_US.UTF-8')  #주행거리 타입 변경
for k in range(len(bus_dist)):
    bus_dist.iloc[k,2]=locale.atof(bus_dist.iloc[k,2])
print(bus_dist.dtypes)
print(bus_dist)


#####노선별 버스 운행대수 분석#####
bus_amount=pd.read_csv("D:/단국대학교/2021-2/AI전공별 활용/2020년 09월 버스운행노선 현황.csv")
bus_amount = bus_amount[(bus_amount['노선\n번호']=='100')|(bus_amount['노선\n번호']=='2016')|(bus_amount['노선\n번호']=='260')|
(bus_amount['노선\n번호']=='273')|(bus_amount['노선\n번호']=='3012')|(bus_amount['노선\n번호']=='440')|
(bus_amount['노선\n번호']=='472')|(bus_amount['노선\n번호']=='601')|(bus_amount['노선\n번호']=='700')|
                        (bus_amount['노선\n번호']=='720')|(bus_amount['노선\n번호']=='7727')]

bus_amount=bus_amount[['노선\n번호','운행\n대수']]
bus_amount.iloc[8,1]=24
bus_amount.iloc[10,1]=28
bus_amount = bus_amount.drop([200,222,223],axis=0)
print(bus_amount)

##x축 노선 순서 맞추기 위해 추가 데이터프레임 생성
bus_dist2 = bus_dist.loc[[4,86,110,116,119,167,179,230,289,308,331],['운행일자','노선','운행거리(Km)','운행건수']]
bus_dist2=bus_dist2.astype({'노선': 'int'})
bus_dist2 = bus_dist2.sort_values(by=['노선'],axis=0)
print(bus_dist2)
bus_dist2=bus_dist2.astype({'노선': 'str'})
print(bus_dist2)
print(bus_dist2.dtypes)


##시각화2
plt.style.use('ggplot')
plt.rcParams['axes.unicode_minus']=False

ax1=bus_amount['운행\n대수'].plot(kind='bar',color='coral',stacked=True)
ax2=ax1.twinx()
ax2.plot(bus_dist2['노선'],bus_dist2['운행거리(Km)'],ls='--',marker='o',markersize=5,color='green',label='운행거리(Km)')

plt.title('노선 별 운행대수')
ax1.set_ylabel('운행대수',size=10)
ax1.set_xlabel('노선',size=10)
ax2.set_ylabel('운행거리(Km)',size=10)
#plt.legend()
plt.show()




