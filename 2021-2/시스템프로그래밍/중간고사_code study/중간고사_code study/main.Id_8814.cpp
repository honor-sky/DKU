#include <stdio.h>

int a = 10; //��������

int func1(int arg1) { //�Լ� ����
	printf("ln func1:arg1 = %d\n", arg1);
}

int main() {
	
	int* pa; //������ ������
	int(*func_ptr)(int); //�Լ�������

	pa = &a;
	printf("pa = %p,*pa = %d\n", pa, *pa); //pa�� �ּڰ� ���, pa�� ����Ű�� �� ��� //�ּڰ�, 10
	func1(3); //3���

	func_ptr = func1; //�Լ� �����Ϳ� �Լ��� �̸�=�Լ��� �ּ� �Ҵ�
	func_ptr(5);//�Լ� ȣ��� �Ȱ��� ��� ���� //5 ���

}