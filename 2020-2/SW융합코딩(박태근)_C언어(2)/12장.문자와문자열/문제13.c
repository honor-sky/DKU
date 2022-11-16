#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {

	char str[30];
	int count = 0;

	printf("문자열을 입력하시오: ");
	gets_s(str, sizeof(str));

	for (int i = 0; i < strlen(str); i++) {
		if (ispunct(str[i])) {
			count++;
		}
	}
	printf("구두점의 개수는 %d입니다.", count);

	return 0;
}













