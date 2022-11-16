#include <stdio.h>


struct point {
	int x, y;
};

int quadrant(struct point p1) {
	if (p1.x > 0 && p1.y > 0) { //제 1사분면의 x,y범위
		return 1;
	}
	else if (p1.x < 0 && p1.y >0) {//제 2사분면의 x,y범위
		return 2;
	}
	else if (p1.x < 0 && p1.y < 0) {//제 3사분면의 x,y범위
		return 3;
	}
	else if (p1.x > 0 && p1.y < 0) {  //제 4사분면의 x,y범위
		return 4;
	}
}

int main(void) {

	struct point p = { -1,2 };
	int result = quadrant(p);

	printf("(%d,%d)의 사분면 = %d", p.x, p.y, result);

	return 0;
}
