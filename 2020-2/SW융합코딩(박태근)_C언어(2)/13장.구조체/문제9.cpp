#include <stdio.h>
#include <ctype.h>

struct food {
	char name[100];
	int calories;
};

int main(void) {

	struct food array[3] = {
		{"�����",600},
		{"ġŲ",1000},
		{"ȸ����",500}
	};
	int cal_sum = 0;
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
		cal_sum += array[i].calories;
	}
	printf("�� Į�θ�=%d", cal_sum);

	return 0;
}


