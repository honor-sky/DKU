#include <stdio.h>
#include <string.h>

char s[100];
char* token;

int main(void) {

	printf("공백 문자가 있는 문자열을 입력하시오: ");
	gets_s(s, sizeof(s)); //문자열 입력

	token = strtok(s, " ");//token에 주소값을 반환
	while (token != NULL) {//strtok(NULL,”“)때문에 마지막에 token은 NULL돼서 이렇게 해야함
		printf("%s", token);
		token = strtok(NULL, " "); //마지막엔 token이 NULL이 된다.
	}

	return 0;
}


