#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {

	char str[80];
	char str2[80] = { NULL }; //NULL�� �ʱ�ȭ 
	char finding_str[20];//ã�� ���ڿ� //�迭�� ���� �����͸� ���� �����غ���
	char change_str[20];//�ٲ� ���ڿ�

	printf("���ڿ��� �Է��Ͻÿ�: ");
	gets_s(str, 80);
	printf("ã�� ���ڿ�: ");
	gets_s(finding_str, 20);
	printf("�ٲ� ���ڿ�: ");
	gets_s(change_str, 20);

	char* token = strtok(str, " ");
	while (token != NULL) {
		if (strcmp(token, finding_str) == 0) {   //strstr�� ���� ����� �����غ���
			strcat(str2, change_str);
		}
		else {
			strcat(str2, token);
		}
		strcat(str2, " ");
		token = strtok(NULL, " ");
	}
	printf("������ ���ڿ�: %s", str2);

	return 0;
}














