#include <stdio.h>

typedef struct employee {
	char name[20];
	int age;
}EMPLOYEE;


int main(void) {
	EMPLOYEE array[10]{ //����ü �迭 ���� �� �ʱ�ȭ
		{"ȫ�浿1",20},
		{"ȫ�浿2",25},
		{"ȫ�浿3",43},
		{"ȫ�浿4",55},
		{"ȫ�浿5",33},
		{"ȫ�浿6",40},
		{"ȫ�浿7",38},
		{"ȫ�浿8",23},
		{"ȫ�浿9",29},
		{"ȫ�浿10",35}
	};
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
		if (20 <= array[i].age && array[i].age <= 30) { //20 <= array[i].age<=30 �̷��� �� ���� X
			printf("�̸�=%s ����=%d\n", array[i].name, array[i].age);
		}
	}

	return 0;
}



