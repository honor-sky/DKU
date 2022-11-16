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
void Insertion(int* arr, int n) {

	for (int i = 1; i < n; i++) {
		int key = arr[i];
		int j;
		for (j = i - 1; j >= 0 && arr[j] > key; j--) {
			arr[j+1] = arr[j];
		}
		arr[j+1] = key;	
	}
	//printf("\n���� ����\n");
	//printArray(arr, n);

}

//���� ����
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
	//printf("\n���� ����\n");
	//printArray(arr, n);

}

//���� ����
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