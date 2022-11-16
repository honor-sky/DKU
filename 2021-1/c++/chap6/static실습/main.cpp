/*#include <iostream>
using namespace std;

class Simple {
    //int count=0; //클래스 내 private 함수 객체마다 생성//외부에서 접근 X
    //static int count;//클래스의 private 공유 멤버(외부접근불가)
				 //반드시 클래스 외부에서 공간 할당 선언 및 초기화 필요
public:
	static int count;
	Simple() {
		count++;
		cout << count << endl;
	}
};
int Simple::count=0;

int main() {
	Simple s1;
	Simple s2;

	
}*/

#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int r = 0) :radius(r){} //r값을 바로 radius에 저장
	void show() {
		cout << "radius = " << radius;
	}
	Circle operator+(int x) { //연산자 중복 함수//반지름에 더할 정수를 x로 받아옴
		Circle tmp; //임시 Circle 객체 
		tmp.radius = this->radius + x; //임시 Circle객체의 radius = 연산자호출객체의radius+x 
		return tmp; //임시 객체tmp의 복사본 반환
	}

};

int main() {
	Circle a(5), b;
	b = a + 8; //객체 a에서 반지름이+3 된 후에 객체가 b로 반환
	b.show();
}