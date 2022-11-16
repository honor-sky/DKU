/*sorting algorithm /kyungmin Kim/2021.10.09*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Sorting.h"

int* array(int n) {  //배열 동적생성
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
	srand((unsigned)time(NULL)); //실행마다 다른 난수 생성
	for (int i = 0; i < n; i++) {
		arr[i] = ((double)rand() / 32767) * (1000000 - 10000) + 10000 + 0.5;//10000~1000000
	}	
		
}

//삽입 정렬
void Ins