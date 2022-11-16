#include <iostream>
using namespace std;

class MyIntStack {
	int* p; //���ø޸𸮷� ����� ������
	int size; //������ �ִ� ũ��
	int tos; // ������ ž�� ����Ű�� �ε���

public:
	MyIntStack();
	MyIntStack(int size);
	MyIntStack(MyIntStack& s); //���������
	~MyIntStack();
	bool push(int n); //���� n�� ���ÿ� Ǫ��//�� ���� flase
	bool pop(int& n);//������ ž ���� n�� pop//��������� false
};

MyIntStack::MyIntStack()
{	this->size = 10;
	this->p = new int[size];
	tos = 100;
}

MyIntStack::MyIntStack(int size)
{   this->size = size;
    this->p = new int[size];
	tos = 100;
}

MyIntStack::~MyIntStack() {
	delete p;
}

MyIntStack::MyIntStack(MyIntStack& s) {
	this->size = s.size;
	this->p = new int[this->size];
	if (tos != 100) {
		for (int i = 0; i <= s.tos; i++) {
			this->p[i] = s.p[i];
		}
	}
	this->tos = s.tos;

}

bool MyIntStack::push(int n) {
	if (tos == 100) {
		tos = 0;
		p[tos] = n;
		return true;
	}
	if (tos != 10) {
		tos++;
		p[tos] = n;
		return true;
	}
	return false;
}

bool MyIntStack::pop(int& n) {//pop�ϸ� top�� ���ֳ�?
	if (*p != NULL) {
		n = p[tos];
		p[tos] = NULL;
		if (tos == 0) {
			tos = 100;
			return true;
		}
		tos--;
		return true;
	}
	return false;
}


int main() {
	MyIntStack a(10);
	a.push(10);
	a.push(20);
	MyIntStack b = a; //���� ����
	b.push(30);

	int n;
	a.pop(n);
	cout << "���� a���� ���� ��" << n << endl;
	b.pop(n);
	cout << "���� b���� ���� ��" << n << endl;
	b.push(40);
	b.pop(n);
	cout << "���� b���� ���� ��" << n << endl;
	b.pop(n);
	cout << "���� b���� ���� ��" << n << endl;
	b.pop(n);
	cout << "���� b���� ���� ��" << n << endl;

}