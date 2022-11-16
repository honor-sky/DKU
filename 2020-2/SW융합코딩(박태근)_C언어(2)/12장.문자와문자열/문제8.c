#include <stdio.h>
#include <string.h>

int main(void) {

	char str[100];
	int count = 0;
	printf("문자열을 입력하시오: ");
	gets_s(str, 100);

	//문자열을 토큰으로 분리해 단어 개수 세기
	char* token;
	token = strtok(str, " ");
	while (token != NULL) {
		count++;
		token = strtok(NULL, " ");
	}
	printf("단어의 수는 %d입니다.", count);

	return 0;
}








