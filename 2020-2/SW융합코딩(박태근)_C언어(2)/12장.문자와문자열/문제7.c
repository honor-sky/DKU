#include <stdio.h>
#include <string.h>
#include <ctype.h>

int get_response(char* prompt) {

	printf("%s", prompt);

	char answer[10];
	gets_s(answer, 10);
	//answer�� ���ڿ��� ��� �ҹ��ڷ� ����//����� ���ϱ� ���ؼ�
	for (int i = 0; i < strlen(answer); i++) {
		if (isupper(answer[i])) {
			answer[i] = tolower(answer[i]);
		}
	}
	if (strcmp(answer, "no") == 0) {//���ڿ� ��ġ
		return 0;
	}
	else if (strcmp(answer, "yes") || strcmp(answer, "ok") == 0) {
		return 1;
	}

}

int main(void) {

	char str[100] = "������ �Ͻðڽ��ϱ�?";
	int answer = get_response(str); //���� ���� ����

	if (answer == 0) {
		printf("�������� �亯");
	}
	else {
		printf("�������� �亯");
	}

	return 0;
}







