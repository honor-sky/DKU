#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char name[100];
	int max_size;
	char max_name[30];

	cout << "5 ���� �̸��� ';'���� �����Ͽ� �Է��ϼ���" << endl << ">>";
	for (int i = 1; i <= 5;i++) {
		cin.getline(name, 100, ';'); //�Է� ����
		cout << i << " : " << name << endl;
		//������;�� ���� ; ���� ���� name�� �����ϴ� �� ó�� �ִٰ� ���
		//���� �� �� ����, name���� �ô��� �ٸ� ���ڿ�; ������ �ٽ� ���
		
		if (i == 1) {
			max_size = strlen(name);
			strcpy_s(max_name,name);
		}
		if (max_size < strlen(name)) {
			strcpy_s(max_name, name);
			max_size = strlen(name);
		}
	}//������ ;�̰� ���� ġ�� �� �� ��µ�..����//getline ���� �������� �����ʿ�

	cout << "���� �� �̸���" << max_name;
}



