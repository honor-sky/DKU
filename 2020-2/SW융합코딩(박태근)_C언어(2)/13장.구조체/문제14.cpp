/*#include <stdio.h>

struct music {
	char title[20];
	char singer[20];
	char location[50]; //mp3 속 곡의 위치
	int type; //장르
}flie_arr[100];

void add(int add_num);
void print();
char* search();
int add_num = 0; //배열 안에 저장된 구조체의 개수(곡의 개수)
int main(void){

	while (1) {
		printf("================");
		printf("1. 추가\n2. 출력\n3. 검색\n4. 종료");
		printf("================");
		int key;
		scanf("%d", &key);
		if (key == 1) { //곡 추가
			add(add_num);
			add_num++;
		}
		else if (key == 2) {//곡 출력

		}
		else if (key == 3) {//곡 검색

		}
		else { //종료
			break;
		}
	}

	return 0;
}
void add(int add_num) { //곡을 추가하는 함수
	printf("제목:\n");
	gets_s(flie_arr[add_num].title, 20);
	printf("가수:\n");
	gets_s(flie_arr[add_num].singer, 20);
	printf("위치:\n");
	gets_s(flie_arr[add_num].location, 50);
	printf("장르:\n");
	gets_s(flie_arr[add_num].type, sizeof(int));
}
void print() { //곡을 출력하는 함수
	printf("출력할 곡의 제목을 적으시오\n");
	char title[20];
	gets_s(title, sizeof(title));

}
char* search() {
	return
}*/







