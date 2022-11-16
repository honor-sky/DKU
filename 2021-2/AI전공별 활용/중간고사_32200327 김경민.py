#32200327 김경민
import pandas as pd  #1
import matplotlib.pyplot as plt
from matplotlib import font_manager, rc

font_path = "./malgun.ttf"
font_name =font_manager.FontProperties(fname=font_path).get_name()
rc('font',family=font_name)
plt.rcParams.update({'font.family':'Malgun Gothic','font.size':12})

df = pd.read_csv("./소상공인상권정보.csv") #2
print("컬럼 항목 수: ",len(df.columns)) #3
#print('\n')
print(df.columns) #4

print("============================================")
print(set(df['상권업종대분류명'])) #5
print("============================================")
print(set(df['상권업종중분류명']))
print("============================================")

dataset = df[['상호명', '지점명', '상권업종대분류명', '상권업종중분류명', '시도명', '시군구명', '행정동명', '위도', '경도']] #6
#print(dataset)

print(dataset.head()) #7

df_coffee=dataset[(dataset['시도명']=='서울특별시')&(df['상권업종중분류명']=='커피점/카페')] #8
print(df_coffee.tail(10)) #9

print("서울시내 커피 전문점 점포 수:",len(df_coffee)) #10
df_coffee=df_coffee.reset_index().drop('index',axis=1)#11
#print(df_coffee)
print(df_coffee.head())#12

df_seoul_ediya = df_coffee[(df_coffee['상호명']=='이디야커피')] #13
df_seoul_ediya=df_seoul_ediya.reset_index().drop('index',axis=1) #!4
#print(df_seoul_ediya)
print("서울시내 이디야 커피 점포 수: ",len(df_seoul_ediya)) #15
print(df_seoul_ediya.head()) #16

ediya_gu=df_seoul_ediya.groupby('시군구명').count() #17
#print(ediya_gu)

ediya_gu=ediya_gu.sort_values(by='상호명',ascending=False) #18
#print(ediya_gu)
print('\n')

#19
ediya_gu=ediya_gu['상호명'] # 이미 groupby를 사용하여 인덱스가 '시군구명'으로 지정되었고, 그림과 같이 출력하기 위해 상호명만 출력
print(ediya_gu)

#20
plt.figure(figsize=(14,12))
plt.style.use('ggplot')
ediya_gu.plot(kind='bar',color='blue')
plt.title('구별 이디야 매장수')
plt.ylabel('매장수',size=30)
plt.xlabel('구별',size=30)
plt.legend()
plt.show()
