#include <stdio.h>

struct card {
	int value;
	char suit;
};

int main(void) {

	struct card card_arr[52];
	for (int k = 0; k < 4; k++) {
		int type = k;
		for (int i = 0; i < 13; i++) { //ÃÊ±âÈ­
			card_arr[i + 13 * k].value = i + 1;
			switch (type) {
			case 0:
				card_arr[i + 13 * k].suit = 'c'; //ÀÎµ¦½º 0~12
			case 1:
				card_arr[i + 13 * k].suit = 'd'; //ÀÎµ¦½º 13~25
			case 2:
				card_arr[i + 13 * k].suit = 'h'; //ÀÎµ¦½º 26~38
			case 3:
				card_arr[i + 13 * k].suit = 's'; //ÀÎµ¦½º 39~51
			}
		}
	}

	for (int i = 0; i < sizeof(card_arr) / sizeof(card_arr[0]); i++) {
		printf("%d : %c ", card_arr[i].value, card_arr[i].suit);
	}
	return 0;
}





