#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {

	char str[100];
	char reverse_str[100] = { NULL }; //NULL�� �ʱ�ȭ //�ʱ�ȭ �� ��Ű�� ������ ��� ���ɼ� ����
	char* str2[20]; //������ �ܾ��� �ּڰ��� �����ϴ� ������ �迭

	printf("���ڿ��� �Է��Ͻÿ�:");
	gets_s(str, 100);

	int i = 0;
	char* token = strtok(str, " "); //�ʱ� token 
	while (token != NULL) {
		str2[i++] = token; //������ �ܾ��� �ּڰ��� str2�迭�� ����
		token = strtok(NULL, " "); //���� ��ū ����	
	}
	for (int j = i - 1; j >= 0; j--) {
		strcat(reverse_str, str2[j]);
		strcat(reverse_str, " ");
	}
	printf("%s", reverse_str);

	return 0;
}











