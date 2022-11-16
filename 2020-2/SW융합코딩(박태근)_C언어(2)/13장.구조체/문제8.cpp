#include <stdio.h>
#include <math.h>
#define PI 3.141592

struct point {  //원의 중심으로 쓰일 x,y값을 갖는 구조체
	int x, y;
};
typedef struct circle {
	struct point center; //원의 중심
	double radius; //반지름
}CIRCLE;

double area(CIRCLE c) {
	return (PI * pow(c.radius, 2));
}
double perimeter(CIRCLE c) {
	return (PI * 2 * c.radius);
}

int main(void) {

	CIRCLE c1;
	c1.center.x = 0;
	c1.center.y = 0;
	c1.radius = 10;
	printf("원의 중심점: %d %d\n", c1.center.x, c1.center.y);
	printf("원의 반지름: %f\n", c1.radius);

	double circle_area = area(c1);
	double circle_perimeter = perimeter(c1);
	printf("원의 면적=%f, 원의 둘레=%f", circle_area, circle_perimeter);

	return 0;
}

