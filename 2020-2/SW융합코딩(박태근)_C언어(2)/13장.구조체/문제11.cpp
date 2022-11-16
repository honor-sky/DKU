#include <st#include <stdio.h>
#include <string.h>

struct call_num_book {
	char name[10];
	char home_number[15]; //집 전화번호
	char phone_number[15]; //폰 전화번호
};

int main(void) {
	struct call_num_book book1[3];
	for (int i = 0; i < 3; i++) {
		printf("이름을 입력하시오:");
		gets_s(book1[i].name, sizeof(book1[i].name));
		printf("집전화번호를 입력하시오:");
		gets_s(book1[i].home_number, sizeof(book1[i].home_number));
		printf("휴대번호를 입력하시오:");
		gets_s(book1[i].phone_number, sizeof(book1[i].phone_number));
	}

	char search_name[10];
	printf("검색할 이름을 입력하시오:");
	gets_s(search_name, sizeof(search_name));
	for (int i = 0; i < 3; i++) {
		if (strcmp(book1[i].name, search_name) == 0) {
			printf("\n%s\n", book1[i].home_number);
			printf("%s\n", book1[i].phone_number);
		}
	}



	return 0;
}




