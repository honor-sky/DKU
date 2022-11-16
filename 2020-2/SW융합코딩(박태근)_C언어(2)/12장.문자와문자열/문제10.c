#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {

	char str[100];
	printf("텍스트를 입력하시오:");
	gets_s(str, 100); //검사 할 문자열 입력

	for (int i = 0; i < strlen(str); i++) { //대소문자 구별 x이므로 싹 다 소문자로 바꾸기
		if (isupper(str[i])) {
			str[i] = tolower(str[i]);
		}
	}
	//회문여부 검사
	int k = 0;
	int j = strlen(str) - 1;

	while (1) {
		if (k > j) {
			printf("회문입니다.");
			break;
		}
		if (str[k] != str[j]) {
			printf("회문이 아닙니다.");
			break;
		}
		k++;
		j--;

	}

	return 0;
}










