/*#include <iostream>
using namespace std;

class Simple {
    //int count=0; //Ŭ���� �� private �Լ� ��ü���� ����//�ܺο��� ���� X
    //static int count;//Ŭ������ private ���� ���(�ܺ����ٺҰ�)
				 //�ݵ�� Ŭ���� �ܺο��� ���� �Ҵ� ���� �� �ʱ�ȭ �ʿ�
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
	Circle(int r = 0) :radius(r){} //r���� �ٷ� radius�� ����
	void show() {
		cout << "radius = " << radius;
	}
	Circle operator+(int x) { //������ �ߺ� �Լ�//�������� ���� ������ x�� �޾ƿ�
		Circle tmp; //�ӽ� Circle ��ü 
		tmp.radius = this->radius + x; //�ӽ� Circle��ü�� radius = ������ȣ�ⰴü��radius+x 
		return tmp; //�ӽ� ��ütmp�� ���纻 ��ȯ
	}

};

int main() {
	Circle a(5), b;
	b = a + 8; //��ü a���� ��������+3 �� �Ŀ� ��ü�� b�� ��ȯ
	b.show();
}