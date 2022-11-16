#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* str_upper(char* s) {
	for (int i = 0; i < strlen(s); i++) {
		if (islower(s[i])) {
			s[i] = toupper(s[i]);
		}
	}
	return s;
}

int main(void) {

	char str[100];
	printf("문자열을 입력하시오:");
	gets_s(str, 100);
	strcpy(str, str_upper(str));//함수 호출 및 문자열 배열의 주솟값 전달

	printf("변환된 문자열 : %s", str);

	return 0;
}
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* str_upper(char* s) {
	for (int i = 0; i < strlen(s); i++) {
		if (islower(s[i])) {
			s[i] = toupper(s[i]);
		}
	}
	return s;
}

int main(void) {

	char str[100];
	printf("문자열을 입력하시오:");
	gets_s(str, 100);
	strcpy(str, str_upper(str));//함수 호출 및 문자열 배열의 주솟값 전달

	printf("변환된 문자열 : %s", str);

	return 0;
}






