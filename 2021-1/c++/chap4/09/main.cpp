#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Person {
	string name;
	string tel;
public:
	Person() {};
	string getName() {
		return name;
	}
	string getTel() {
		return tel;
	}
	void set(string name, string tel) {
		this -> name = name;
		this->tel = tel;
	}
};

int main() {
	Person p_Array[3];
	string name;
	string tel;
	
	cout << "�̸��� ��ȭ��ȣ�� �Է����ּ���"<<endl<<"��� 1>> ";
	cin >> name >> tel;
	p_Array[0].set(name, tel);
	cout <<  "��� 2>> ";
	cin >> name >> tel;
	p_Array[1].set(name, tel);
	cout << "��� 3>> ";
	cin >> name >> tel;
	p_Array[2].set(name, tel);

	cout << "��� ����� �̸��� ";
	for (int i = 0; i < 3; i++) {
		cout << p_Array[i].getName() << " ";
	}
	cout << "��ȭ��ȣ�� �˻��մϴ�. �̸��� �Է��ϼ���>>";
	cin >> name;
	for (int i = 0; i < 3; i++) {
		if (p_Array[i].getName()==name) {
			cout <<endl<<"��ȭ ��ȣ�� "<< p_Array[i].getTel();
		}
	}
}