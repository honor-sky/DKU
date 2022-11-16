#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {

	char str[100];
	char reverse_str[100] = { NULL }; //NULL로 초기화 //초기화 안 시키면 괴문자 출력 가능성 있음
	char* str2[20]; //추출한 단어의 주솟값을 저장하는 포인터 배열

	printf("문자열을 입력하시오:");
	gets_s(str, 100);

	int i = 0;
	char* token = strtok(str, " "); //초기 token 
	while (token != NULL) {
		str2[i++] = token; //추출한 단어의 주솟값을 str2배열에 저장
		token = strtok(NULL, " "); //다음 토큰 추출	
	}
	for (int j = i - 1; j >= 0; j--) {
		strcat(reverse_str, str2[j]);
		strcat(reverse_str, " ");
	}
	printf("%s", reverse_str);

	return 0;
}











