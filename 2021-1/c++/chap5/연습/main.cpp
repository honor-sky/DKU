#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

/*
class Circle {
public:
	int radius;
	char* name;
	Circle(int r,const char* str) {
		this->radius = r;
		this->name = new char[strlen(str + 1)];
		strcpy(this->name, str);
	}
	~Circle() {}
};
void change(Circle c) { //��������
	strcpy(c.name, "hhhh");
	c.radius = 100;
}

int main() {
	Circle waffle(10,"ssss");
	change(waffle);
	cout << waffle.name<<","<<waffle.radius;


	return 0;
}*/
class Circle {
public:
	char* name;
	char array[5] = "kkkk";
	Circle() {
		name = array;
	}
	~Circle() {}
};

int main() {
	Circle c;
	cout << c.name;//�迭�� ����Ű�� �� ����Ű�� ���� ��, ����� ���� ���
}