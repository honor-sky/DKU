#include <stdio.h>
#include <math.h>
#define PI 3.141592

struct point {  //���� �߽����� ���� x,y���� ���� ����ü
	int x, y;
};
typedef struct circle {
	struct point center; //���� �߽�
	double radius; //������
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
	printf("���� �߽���: %d %d\n", c1.center.x, c1.center.y);
	printf("���� ������: %f\n", c1.radius);

	double circle_area = area(c1);
	double circle_perimeter = perimeter(c1);
	printf("���� ����=%f, ���� �ѷ�=%f", circle_area, circle_perimeter);

	return 0;
}

