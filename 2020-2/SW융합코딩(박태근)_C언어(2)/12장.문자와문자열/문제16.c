#include <stdio.h>
#include <string.h>
#include <ctype.h>

//전광판 만들기
int main(void) {

	char* str_pointer;
	char str[100] = { NULL };
	printf("광고하고 싶은 텍스트를 입력하시오: ");//call NOW and you'll get free shipping
	gets_s(str, sizeof(str));
	str_pointer = str; //문자열의 주소값을 포인터 배열에 저장
	printf("======================\n");

	//포인터가 문자열의 가장 처음을 가르키고 있고,거기서부터 특정 길이만큼 출력을 반복하는데
	//만약 입력한 문자열이 끝이 나면 다시 처음으로 돌아옴
	int i = 0;
	for (int k = 0; k < 10; k++) {
		if (strcmp(str_pointer, "\0") == 0) {
			str_pointer = str;
		}
		for (int i = 0; i < strlen(str); i++) {
			if (strcmp(str_pointer, "\0") == 0) {
				str_pointer = str; //문자열이 끝나 str_pointer가 NULL를 가리키면 다시 처음을 가리킴
			}
			printf("%c", *str_pointer);
			str_pointer += 1; //다음 문자 가리킴
		}
		str_pointer = str + ++i;
		printf("\n");
	}

	return 0;
}















