#include <stdio.h>
#include <string.h>

int main(void) {

	char str[100];
	int count = 0;
	printf("���ڿ��� �Է��Ͻÿ�: ");
	gets_s(str, 100);

	//���ڿ��� ��ū���� �и��� �ܾ� ���� ����
	char* token;
	token = strtok(str, " ");
	while (token != NULL) {
		count++;
		token = strtok(NULL, " ");
	}
	printf("�ܾ��� ���� %d�Դϴ�.", count);

	return 0;
}








