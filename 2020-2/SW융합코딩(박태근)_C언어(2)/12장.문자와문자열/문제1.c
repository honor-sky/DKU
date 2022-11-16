/*문제1*/
#include <stdio.h>

int main(void) {
	char c;

	printf("문자를 입력하시오:");
	c = getchar();      // scanf("%c\n", &c);사용하면 안 되는 이유는 뭘까?

	printf("아스키 코드값=%d", c);


	return 0;
}
