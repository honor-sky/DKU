#include <stdio.h>
#include <string.h>

int str_chr(char* s, int c) {
	int result = 0;

	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == (char)c) { //s[i]�� ���ڸ� ��ȯ�ϰ� c�� ������ ��ȯ���Ƿ� c�� char������ �ٲ���� ��
			result++;
		}
	}
	return result;
}

int main(void) {

	char s[20]; //���ڿ� �Է¹��� �迭 ����
	int c;
	int result;

	printf("���ڿ��� �Է��Ͻÿ�: ");
	gets_s(s, sizeof(s)); //���ڿ� �Է�
	printf("������ �� ���ڸ� �Է��Ͻÿ�: ");
	scanf("%c", &c);

	result = str_chr(s, c);
	printf("%c�� ����: %d", c, result);

	return 0;
}



