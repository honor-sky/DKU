#include <stdio.h>
#include <string.h>

int str_chr(char* s, int c) {
	int result = 0;

	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == (char)c) { //s[i]는 문자를 반환하고 c는 정수를 반환마므로 c를 char형으로 바꿔줘야 함
			result++;
		}
	}
	return result;
}

int main(void) {

	char s[20]; //문자열 입력받을 배열 생성
	int c;
	int result;

	printf("문자열을 입력하시오: ");
	gets_s(s, sizeof(s)); //문자열 입력
	printf("개수를 셀 문자를 입력하시오: ");
	scanf("%c", &c);

	result = str_chr(s, c);
	printf("%c의 개수: %d", c, result);

	return 0;
}



