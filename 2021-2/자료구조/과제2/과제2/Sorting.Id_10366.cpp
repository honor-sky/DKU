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
void Insertion(int* arr, int n) {

	for (int i = 1; i < n; i++) {
		int key = arr[i];
		int j;
		for (j = i - 1; j >= 0 && arr[j] > key; j--) {
			arr[j+1] = arr[j];
		}
		arr[j+1] = key;	
	}
	//printf("\n삽입 정렬\n");
	//printArray(arr, n);

}

//버블 정렬
void Bubble(int* arr, int n){
	int temp;

	for (int i = 0; i < n - 1; i++) {
		for (int j = 1; j < n; j++) {
			if (arr[j-1] > arr[j]) {
				temp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = temp;
			}
		}
	}
	//printf("\n버블 정렬\n");
	//printArray(arr, n);

}

//선택 정렬
void Selection(int* arr, int n){
	int temp;

	for (int i = 0; i < n-1;i++){
		int least = i;
		for (int j = i+1; j < n; j++) {
			if ( arr[j]< arr[least]) {
				least = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[least];
		arr[least] = temp;

	}
	//print