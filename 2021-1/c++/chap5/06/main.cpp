#include <iostream>
#include <cstring>
using namespace std;

char& find(char a[], char c, bool& success) { //a �ٲٸ� ������ �ٲ�
	char* ptr = strchr(a, c);

	if (ptr != NULL) {
		success = true;
		return *(ptr);
	}
	success = false;

}

int main() {
	char s[] = "Mike";
	bool b = false;
	char& loc = find(s, 'M', b); //���� ���� ȣ�� ������ s�� �迭�̶� �޸𸮰���
	if (b == false) {
		cout << "M�� �߰��� �� ����." << endl;
		return 0;
	}
	loc = 'm'; //M��ġ�� m���
	cout << s << endl;
}