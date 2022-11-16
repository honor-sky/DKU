#include <stdio.h>
#include <string.h>
#include <ctype.h>

int get_response(char* prompt) {

	printf("%s", prompt);

	char answer[10];
	gets_s(answer, 10);
	//answer의 문자열을 모두 소문자로 만듬//제대로 비교하기 위해서
	for (int i = 0; i < strlen(answer); i++) {
		if (isupper(answer[i])) {
			answer[i] = tolower(answer[i]);
		}
	}
	if (strcmp(answer, "no") == 0) {//문자열 일치
		return 0;
	}
	else if (strcmp(answer, "yes") || strcmp(answer, "ok") == 0) {
		return 1;
	}

}

int main(void) {

	char str[100] = "게임을 하시겠습니까?";
	int answer = get_response(str); //질문 전달 받음

	if (answer == 0) {
		printf("부정적인 답변");
	}
	else {
		printf("긍정적인 답변");
	}

	return 0;
}







