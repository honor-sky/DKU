#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {

	char name[20];
	char* fname; //���� ������ ������ ������  //NULL�� �ʱ�ȭ 
	char* sname; //�̸��� ������ �ּڰ��� �����ϴ� ������  //NULL�� �ֱ�ȭ

	printf("���� �̸��� �빮�ڷ� �Է��Ͻÿ�:");
	gets_s(name, sizeof(name)); //sizeof�� ���� �迭 ũ�⸦ �ٲ㵵 ���� ���� �� �ص� �ȴ�.

	for (int i = 0; i < strlen(name); i++) {
		name[i] = tolower(name[i]);
	}

	fname = strtok(name, " "); //�� ������ fname�� �ε���0�� �ּҰ� ����
	sname = strtok(NULL, " "); //�̸� ������ sname�� �ε���0�� �ּҰ� ����

	printf("%s, %s", sname, fname);

	return 0;
}












