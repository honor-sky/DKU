#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {

	char str[100];
	printf("�ؽ�Ʈ�� �Է��Ͻÿ�:");
	gets_s(str, 100); //�˻� �� ���ڿ� �Է�

	for (int i = 0; i < strlen(str); i++) { //��ҹ��� ���� x�̹Ƿ� �� �� �ҹ��ڷ� �ٲٱ�
		if (isupper(str[i])) {
			str[i] = tolower(str[i]);
		}
	}
	//ȸ������ �˻�
	int k = 0;
	int j = strlen(str) - 1;

	while (1) {
		if (k > j) {
			printf("ȸ���Դϴ�.");
			break;
		}
		if (str[k] != str[j]) {
			printf("ȸ���� �ƴմϴ�.");
			break;
		}
		k++;
		j--;

	}

	return 0;
}










