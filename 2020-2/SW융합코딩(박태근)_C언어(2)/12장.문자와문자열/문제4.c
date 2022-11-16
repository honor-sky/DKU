#include <stdio.h>
#include <string.h>


char s[20]; //문자열 입력받을 배열 생성
int alpa[26] = { 0 };
//alpa가 str_chr함수 안에 정의되어 있을 경우, 지역변수로 사용되어 main으로 반환해도 값이 사라짐

int* str_chr(char* s) {

	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == NULL) { //공백일 경우 넘어감
			continue;
		}
		else { //해당 문자의 아스키코드-97을 해 그 값을 증가시킴
			alpa[s[i] - 97] ++;
		}
	}
	return alpa; //배열은 이름이 주소값이므로 그냥 배열 이름쓰면 주소값을 반환


}
int main(void) {


	printf("문자열을 입력하시오: ");
	gets_s(s, sizeof(s)); //문자열 입력

	int* result = str_chr(s); //주소값을 반환

	for (int i = 0; i < 26; i++) {
		printf("%c: %d\n", (char)(i + 97), result[i]);
	}

	return 0;
}




