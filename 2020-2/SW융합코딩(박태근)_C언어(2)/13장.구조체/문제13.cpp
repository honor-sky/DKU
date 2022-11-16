#include <stdio.h>
#include <math.h>
#define PI 3.14

struct shape {
	int type;
	union { // ����ü���� ����ü�� ��� �ȴ�.
		struct {
			int base, height;//�غ�,����
		}tri;
		struct {
			int width, height; //����,����
		}rect;
		struct {
			int radius;//������
		}circle;
	}data;
};



int main(void) {

	enum shape_type { TRI, RECT, CIRCLE }; //������ Ÿ���� ���������� ����
	struct shape s;
	enum shape_type shape;
	printf("������ Ÿ���� �Է��Ͻÿ�(0,1,2): ");
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
		printf("�غ��� ������ ���̸� �Է��Ͻÿ�(���� �� 100 200):");
		scanf("%d %d", &s.data.tri.base, &s.data.tri.height);
		printf("������ %f", (s.data.tri.base * s.data.tri.height) % 2);
		break;
	case RECT:
		printf("���ο� ������ ���̸� �Է��Ͻÿ�(���� �� 100 200):");
		scanf("%d %d", &s.data.rect.width, &s.data.rect.height);
		printf("������ %d", s.data.rect.width * s.data.rect.height);
		break;
	case CIRCLE:
		printf("�������� ���̸� �Է��Ͻÿ�(���� �� 10):");
		scanf("%d", &s.data.circle.radius);
		printf("������ %f", PI * pow(s.data.circle.radius, 2));
		break;
	}

	return 0;
}






