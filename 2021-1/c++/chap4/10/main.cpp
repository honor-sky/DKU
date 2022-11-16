#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Person {
	string name;
public:
	Person() {};
	Person(string name) {
		this->name = name;
	}
	string getName() {
		return name;
	}
	void setName(string name) {
		this->name = name;
	}
};
class Family {
	Person* p;
	int size;
public: 
	Family(string name, int size) {
		this->size = size;
		p = new Person[size];
	}
	void show() {
		cout << "Simpson������ ������ ���� 3�� �Դϴ�." << endl;
		for (int i= 0; i < size; i++) {
			cout << p[i].getName() << "\t";
				
		}
	}
	void setName(int n, string name) {
		p[n].setName(name);
	}

	~Family() {
		//delete p; //�̰� ������ ���޼��� ��...
	}
};

int main() {
	Family* simpson = new Family("Simpson", 3);
	simpson->setName(0, "Mr.simpson");
	simpson->setName(1, "Mrs.simpson");
	simpson->setName(2, "Bart simpson");

	simpson->show();
	delete simpson;
}