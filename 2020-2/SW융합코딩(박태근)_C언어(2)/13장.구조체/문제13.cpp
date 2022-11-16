#include <stdio.h>
#include <math.h>
#define PI 3.14

struct shape {
	int type;
	union { // 구조체들이 공용체로 사용 된다.
		struct {
			int base, height;//밑변,높이
		}tri;
		struct {
			int width, height; //가로,세로
		}rect;
		struct {
			int radius;//반지름
		}circle;
	}data;
};



int main(void) {

	enum shape_type { TRI, RECT, CIRCLE }; //도형의 타입을 열거형으로 설정
	struct shape s;
	enum shape_type shape;
	printf("도형의 타입을 입력하시오(0,1,2): ");
	scanf("%d", &s.type);
	if (s.type == 0) {
		shape = TRI;
	}
	else if (s.type == 1) {
		shape = RECT;
	}
	else {
		shape = CIRCLE;
	}

	switch (shape) {
	case TRI:
		printf("밑변과 높이의 길이를 입력하시오(예를 들어서 100 200):");
		scanf("%d %d", &s.data.tri.base, &s.data.tri.height);
		printf("면적은 %f", (s.data.tri.base * s.data.tri.height) % 2);
		break;
	case RECT:
		printf("가로와 세로의 길이를 입력하시오(예를 들어서 100 200):");
		scanf("%d %d", &s.data.rect.width, &s.data.rect.height);
		printf("면적은 %d", s.data.rect.width * s.data.rect.height);
		break;
	case CIRCLE:
		printf("반지름의 길이를 입력하시오(예를 들어서 10):");
		scanf("%d", &s.data.circle.radius);
		printf("면적은 %f", PI * pow(s.data.circle.radius, 2));
		break;
	}

	return 0;
}






