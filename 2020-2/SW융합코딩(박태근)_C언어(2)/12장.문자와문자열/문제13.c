#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {

	char str[30];
	int count = 0;

	printf("���ڿ��� �Է��Ͻÿ�: ");
	gets_s(str, sizeof(str));

	for (int i = 0; i < strlen(str); i++) {
		if (ispunct(str[i])) {
			count++;
		}
	}
	printf("�������� ������ %d�Դϴ�.", count);

	return 0;
}













