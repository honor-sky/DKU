#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {

	char str[80];
	char str2[80] = { NULL }; //NULL로 초기화 
	char finding_str[20];//찾을 문자열 //배열을 쓸지 포인터를 쓸지 생각해보기
	char change_str[20];//바꿀 문자열

	printf("문자열을 입력하시오: ");
	gets_s(str, 80);
	printf("찾을 문자열: ");
	gets_s(finding_str, 20);
	printf("바꿀 문자열: ");
	gets_s(change_str, 20);

	char* token = strtok(str, " ");
	while (token != NULL) {
		if (strcmp(token, finding_str) == 0) {   //strstr을 쓰는 방법도 생각해보기
			strcat(str2, change_str);
		}
		else {
			strcat(str2, token);
		}
		strcat(str2, " ");
		token = strtok(NULL, " ");
	}
	printf("수정된 문자열: %s", str2);

	return 0;
}














