#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int profit=0;
	char coffee[100];
	int num;
	int price;

	cout << "���������� 2000��, �Ƹ޸�ī�� 2300��, īǪġ�� 2500��"<<endl;
	while (profit < 20000) {
		cout << "�ֹ�>> ";
		cin >> coffee >> num;

		if (strcmp(coffee, "����������") == 0) {
			price = num * 2000;
		}
		else if (strcmp(coffee, "�Ƹ޸�ī��") == 0) {
			price = num * 2300;
		}
		else if (strcmp(coffee, "īǪġ��") == 0) {
			price = num * 2500;
		}

		cout << price << "�Դϴ�. ���ְ� �弼��" << endl;
		profit += price;
	}
	cout << "����" << price << "���� �Ǹ��Ͽ� ī�並 �ݽ��ϴ�. ���� ����~~~";
	return 0;
}