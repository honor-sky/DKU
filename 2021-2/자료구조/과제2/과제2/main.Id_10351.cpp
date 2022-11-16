/*sorting algorithm /kyungmin Kim/2021.10.09*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Sorting.h"

int* array(int n) {  //�迭 ��������
	int* arr;

	arr = (int*)malloc(sizeof(int) * n);
	mrand(arr,n);

	return arr;
}

void freeArray(int* arr) {
	free(arr);
}

void printArray(int* arr, int n) {
	int r;

	for (r = 0; r < n; r++){
		printf("%d ", arr[r]);
	}
		
}

void mrand(int * arr,int n) {
	srand((unsigned)time(NULL)); //���ึ�� �ٸ� ���� ����
	for (int i = 0; i < n; i++) {
		arr[i] = ((double)rand() / 32767) * (1000000 - 10000) + 10000 + 0.5;//10000~1000000
	}	
		
}

//���� ����
void Ins