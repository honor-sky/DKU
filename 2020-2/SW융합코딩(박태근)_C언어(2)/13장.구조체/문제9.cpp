#include <stdio.h>
#include <ctype.h>

struct food {
	char name[100];
	int calories;
};

int main(void) {

	struct food array[3] = {
		{"ºñºö¹ä",600},
		{"Ä¡Å²",1000},
		{"È¸µ¤¹ä",500}
	};
	int cal_sum = 0;
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
		cal_sum += array[i].calories;
	}
	printf("ÃÑ Ä®·Î¸®=%d", cal_sum);

	return 0;
}


