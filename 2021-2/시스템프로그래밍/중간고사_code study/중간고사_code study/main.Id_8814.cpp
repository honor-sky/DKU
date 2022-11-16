#include <stdio.h>

int a = 10; //전역변수

int func1(int arg1) { //함수 정의
	printf("ln func1:arg1 = %d\n", arg1);
}

int main() {
	
	int* pa; //정수형 포인터
	int(*func_ptr)(int); //함수포인터

	pa = &a;
	printf("pa = %p,*pa = %d\n", pa, *pa); //pa의 주솟값 출력, pa가 가르키는 값 출력 //주솟값, 10
	func1(3); //3출력

	func_ptr = func1; //함수 포인터에 함수의 이름=함수의 주소 할당
	func_ptr(5);//함수 호출과 똑같이 사용 가능 //5 출력

}