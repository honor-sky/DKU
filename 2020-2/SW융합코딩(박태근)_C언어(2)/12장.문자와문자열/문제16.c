#include <stdio.h>
#include <string.h>
#include <ctype.h>

//������ �����
int main(void) {

	char* str_pointer;
	char str[100] = { NULL };
	printf("�����ϰ� ���� �ؽ�Ʈ�� �Է��Ͻÿ�: ");//call NOW and you'll get free shipping
	gets_s(str, sizeof(str));
	str_pointer = str; //���ڿ��� �ּҰ��� ������ �迭�� ����
	printf("======================\n");

	//�����Ͱ� ���ڿ��� ���� ó���� ����Ű�� �ְ�,�ű⼭���� Ư�� ���̸�ŭ ����� �ݺ��ϴµ�
	//���� �Է��� ���ڿ��� ���� ���� �ٽ� ó������ ���ƿ�
	int i = 0;
	for (int k = 0; k < 10; k++) {
		if (strcmp(str_pointer, "\0") == 0) {
			str_pointer = str;
		}
		for (int i = 0; i < strlen(str); i++) {
			if (strcmp(str_pointer, "\0") == 0) {
				str_pointer = str; //���ڿ��� ���� str_pointer�� NULL�� ����Ű�� �ٽ� ó���� ����Ŵ
			}
			printf("%c", *str_pointer);
			str_pointer += 1; //���� ���� ����Ŵ
		}
		str_pointer = str + ++i;
		printf("\n");
	}

	return 0;
}















