#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* str_upper(char* s) {
	for (int i = 0; i < strlen(s); i++) {
		if (islower(s[i])) {
			s[i] = toupper(s[i]);
		}
	}
	return s;
}

int main(void) {

	char str[100];
	printf("���ڿ��� �Է��Ͻÿ�:");
	gets_s(str, 100);
	strcpy(str, str_upper(str));//�Լ� ȣ�� �� ���ڿ� �迭�� �ּڰ� ����

	printf("��ȯ�� ���ڿ� : %s", str);

	return 0;
}
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* str_upper(char* s) {
	for (int i = 0; i < strlen(s); i++) {
		if (islower(s[i])) {
			s[i] = toupper(s[i]);
		}
	}
	return s;
}

int main(void) {

	char str[100];
	printf("���ڿ��� �Է��Ͻÿ�:");
	gets_s(str, 100);
	strcpy(str, str_upper(str));//�Լ� ȣ�� �� ���ڿ� �迭�� �ּڰ� ����

	printf("��ȯ�� ���ڿ� : %s", str);

	return 0;
}






