#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_PM.h"

int* array(int n) { //�迭 �����Ҵ�
	int* arr;
	arr = (int*)malloc(sizeof(int) * n);
	return arr;
}

void freeArray(int* arr) {  //�����Ҵ� ��ȯ
	free(arr);
}
void stack(char a[],int n) {
	int *stack = array(n); //�������� �迭�� �Ҵ�޾� ���� ����
	int top = -1;  //���ÿ� �ƹ��͵� ���� ���¿����� top

	for (int i = 0; i < n; i++) {
		if (a[i] == '(') { 
			top++;
			stack[top] = i;
		}
		if (a[i] == ')') {
			printf("(%d,%d)\n", stack[top], i);
			stack[top] = NULL;
			top-