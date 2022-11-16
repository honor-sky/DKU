#include <stdio.h>


struct point {
	int x, y;
};

int quadrant(struct point p1) {
	if (p1.x > 0 && p1.y > 0) { //�� 1��и��� x,y����
		return 1;
	}
	else if (p1.x < 0 && p1.y >0) {//�� 2��и��� x,y����
		return 2;
	}
	else if (p1.x < 0 && p1.y < 0) {//�� 3��и��� x,y����
		return 3;
	}
	else if (p1.x > 0 && p1.y < 0) {  //�� 4��и��� x,y����
		return 4;
	}
}

int main(void) {

	struct point p = { -1,2 };
	int result = quadrant(p);

	printf("(%d,%d)�� ��и� = %d", p.x, p.y, result);

	return 0;
}
