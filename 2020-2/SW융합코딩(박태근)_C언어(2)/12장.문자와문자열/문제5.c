#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(void) {

	char c;

	while (1) {
		printf("문자를 입력하시오:");
		c = getchar();  //두번째부터 호출이 불가능...
		//버퍼에는 \n이 들어가 있어서 건너 뛰는 거다..즉, 줄바꿈을 제거해줘야 함
		char c2 = fgetc(stdin); //방법1) 버퍼에 남았던 \n문자를 새로운 char형 c2에 저장해 버퍼 비우기

		if (isupper(c)) { //참이면
			c = tolower(c);
			putchar(c);
			printf("\n");
		}
		else if (islower(c)) {
			c = toupper(c);
			putchar(c);
			printf("\n");
		}
		else if (c == '.') {
			break;
		}
		else {
			printf("경고!");
		}
		//c = getchar(); //방법2) 에버퍼에 남았던 \n을 c에 저장해 버퍼 비우기
	}

	return 0;
}





