#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {

	char s[100];
	printf("텍스트를 입력하시오:");
	gets_s(s, 100); //검사 할 문자열 입력

	if (s[strlen(s) - 1] != '.') { //마침표로 끝나는지 검사
		s[strlen(s)] = '.';
	}
	if (islower(s[0])) { //첫 글자가 대문자인지 검사
		s[0] = toupper(s[0]);
	}
	printf("수정된 텍스트: %s", s);

	return 0;
}









