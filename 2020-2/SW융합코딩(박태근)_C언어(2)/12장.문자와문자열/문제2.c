#include <stdio.h>
#include <string.h>

char s[100];
char* token;

int main(void) {

	printf("���� ���ڰ� �ִ� ���ڿ��� �Է��Ͻÿ�: ");
	gets_s(s, sizeof(s)); //���ڿ� �Է�

	token = strtok(s, " ");//token�� �ּҰ��� ��ȯ
	while (token != NULL) {//strtok(NULL,����)������ �������� token�� NULL�ż� �̷��� �ؾ���
		printf("%s", token);
		token = strtok(NULL, " "); //�������� token�� NULL�� �ȴ�.
	}

	return 0;
}


