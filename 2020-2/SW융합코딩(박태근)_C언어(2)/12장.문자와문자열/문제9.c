#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {

	char s[100];
	printf("�ؽ�Ʈ�� �Է��Ͻÿ�:");
	gets_s(s, 100); //�˻� �� ���ڿ� �Է�

	if (s[strlen(s) - 1] != '.') { //��ħǥ�� �������� �˻�
		s[strlen(s)] = '.';
	}
	if (islower(s[0])) { //ù ���ڰ� �빮������ �˻�
		s[0] = toupper(s[0]);
	}
	printf("������ �ؽ�Ʈ: %s", s);

	return 0;
}









