#include <iostream>
using namespace std;

bool bigger(int a, int b, int& big) {
	if (a == b) {
		return true;
	}
	else {
		if (a > b) {
			big = a;
		}
		else {
			big = b;
		}
		return false;
	}
}

int main() {
	int big;
	int a, b;
	cout << "���� �ΰ��� �Է��Ͻÿ�." << endl;
	cin >> a >> b;
	bool result = bigger(a, b,big);
	if (result == true) {
		cout << "���� �ΰ��� �����ϴ�." << endl;
	}
	else {
		cout << "�� ū ����"<<big<<"�Դϴ�" << endl;
	}

}