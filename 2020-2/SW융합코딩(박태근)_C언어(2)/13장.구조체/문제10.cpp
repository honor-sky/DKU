#include <stdio.h>

typedef struct employee {
	char name[20];
	int age;
}EMPLOYEE;


int main(void) {
	EMPLOYEE array[10]{ //구조체 배열 선언 및 초기화
		{"홍길동1",20},
		{"홍길동2",25},
		{"홍길동3",43},
		{"홍길동4",55},
		{"홍길동5",33},
		{"홍길동6",40},
		{"홍길동7",38},
		{"홍길동8",23},
		{"홍길동9",29},
		{"홍길동10",35}
	};
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
		if (20 <= array[i].age && array[i].age <= 30) { //20 <= array[i].age<=30 이렇게 한 번에 X
			printf("이름=%s 나이=%d\n", array[i].name, array[i].age);
		}
	}

	return 0;
}



