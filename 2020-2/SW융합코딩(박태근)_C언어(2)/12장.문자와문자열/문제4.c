#include <stdio.h>
#include <string.h>


char s[20]; //���ڿ� �Է¹��� �迭 ����
int alpa[26] = { 0 };
//alpa�� str_chr�Լ� �ȿ� ���ǵǾ� ���� ���, ���������� ���Ǿ� main���� ��ȯ�ص� ���� �����

int* str_chr(char* s) {

	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == NULL) { //������ ��� �Ѿ
			continue;
		}
		else { //�ش� ������ �ƽ�Ű�ڵ�-97�� �� �� ���� ������Ŵ
			alpa[s[i] - 97] ++;
		}
	}
	return alpa; //�迭�� �̸��� �ּҰ��̹Ƿ� �׳� �迭 �̸����� �ּҰ��� ��ȯ


}
int main(void) {


	printf("���ڿ��� �Է��Ͻÿ�: ");
	gets_s(s, sizeof(s)); //���ڿ� �Է�

	int* result = str_chr(s); //�ּҰ��� ��ȯ

	for (int i = 0; i < 26; i++) {
		printf("%c: %d\n", (char)(i + 97), result[i]);
	}

	return 0;
}




