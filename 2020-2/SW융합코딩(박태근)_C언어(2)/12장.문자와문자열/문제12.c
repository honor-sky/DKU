#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {

	char name[20];
	char* fname; //성을 추출해 저장할 포인터  //NULL로 초기화 
	char* sname; //이름을 추출해 주솟값을 저장하는 포인터  //NULL로 최기화

	printf("성과 이름을 대문자로 입력하시오:");
	gets_s(name, sizeof(name)); //sizeof를 쓰면 배열 크기를 바꿔도 여긴 수정 안 해도 된다.

	for (int i = 0; i < strlen(name); i++) {
		name[i] = tolower(name[i]);
	}

	fname = strtok(name, " "); //성 추출해 fname의 인덱스0에 주소값 저장
	sname = strtok(NULL, " "); //이름 추출해 sname의 인덱스0에 주소값 저장

	printf("%s, %s", sname, fname);

	return 0;
}












