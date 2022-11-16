#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_PM.h"

int* array(int n) { //배열 동적할당
	int* arr;
	arr = (int*)malloc(sizeof(int) * n);
	return arr;
}

void freeArray(int* arr) {  //동적할당 반환
	free(arr);
}
void stack(char a[],int n) {
	int *stack = array(n); //동적으로 배열을 할당받아 스택 만듬
	int top = -1;  //스택에 아무것도 없는 상태에서의 top

	for (int i = 0; i < n; i++) {
		if (a[i] == '(') { 
			top++;
			stack[top] = i;
		}
		if (a[i] == ')') {
			printf("(%d,%d)\n", stack[top], i);
			stack[top] = NULL;
			top-