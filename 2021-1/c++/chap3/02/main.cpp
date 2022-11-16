#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Date {
public:
	int year,month,day;

	Date(int y, int m, int d) 
		:year(y), month(m), day(d){}

	Date(const char *date) { 
		year = atoi(strtok(_strdup(date), "/")); //_strdup:const char�� char ��������
		month = atoi(strtok(NULL, "/"));
		day = atoi(strtok(NULL, "/"));
	}
	~Date() {
		cout << "deconstruct"<<endl;
	}

	void show() {
		cout << year << "��" << month << "��" << day << "��"<<endl;
	}
	int getYear() {
		return year;
	}
	int getMonth() {
		return month;
	}
	int getDay() {
		return day;
	}
};

int main() {
	Date birth(2014, 3, 20);
	Date independenceDay("1945/8/15"); //const char *
	independenceDay.show();
	cout << birth.getYear() << ',' << birth.getMonth() << ',' << birth.getDay() << endl;     
}