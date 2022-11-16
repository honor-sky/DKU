#include <stdio.h>
#include <stdlib.h>

char* get_word() {
	char* s = (char*)malloc(sizeof(char) * 50);
	if (s == NULL) {
		printf("메모리 할당 오류");
		exit(1);
	}
	printf("단어를 입력하시오:(최대 50글자):");
	scanf("%s", s);

	return s;
}
int main(void) {
	//단어 입력 받는 동적 메모리 생성 함수
	char* word = get_word();
	//출력
	printf("동적 메모리에 저장된 단어는 %s입니다.", word);


	return 0;
}








