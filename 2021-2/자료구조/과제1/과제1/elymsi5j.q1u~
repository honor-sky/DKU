#include <stdlib.h>
#include <stdio.h>
#include "calculate_array.h"

int** array(int rows, int cols) {  //2차원 자료구조 동적생성
	int** arr;
	int i;

	arr = (int**)malloc(sizeof(int) * rows);
	for (i = 0; i < rows; i++)
		arr[i] = (int*)malloc(sizeof(int) * cols);

	return arr;
}


void freeArray(int** arr, int rows, int cols) {
	int r, c;
	for (r = 0; r < rows; r++)
		free(arr[r]);

	free(arr);
}


void printArray(int** arr, int rows, int cols, const char msg[]) {
	int r, c;

	printf("%s\n", msg);
	for (r = 0; r < rows; r++) {
		for (c = 0; c < cols; c++)
			printf("\t %d", arr[r][c]);
		printf("\n");
	}
}

void multiplyArrays(int** res, int** a, int** b, int m, int n, int q) {
	int r, c, k;
	int sum;

	for (r = 0; r < m; r++)
		for (c = 0; c < q; c++) {
			sum = 0;
			for (k = 0; k < n; k++) 
				sum += a[r][k] * b[k][c];
			
			res[r][c] = sum;
		}
}

void plusArrays(int** res, int** a, int** b, int m, int n) {
	int r, c;

	for (r = 0; r < m; r++) {
		for (c = 0; c < n; c++) {
			res[r][c] = a[r][c] + b[r][c];
		}
	}

}

void minusArrays(int** res, int** a, int** b, int m, int n) {
	int r, c;

	for (r = 0; r < m; r++) {
		for (c = 0; c < n; c++) {
			res[r][c] = a[r][c] - b[r][c];
		}
	}
}

void divisionArrays(int** res, int** a, int** b, int m, int n) {
	int r, c;

	for (r = 0; r < m; r++) {
		for (c = 0; c < n; c++) {
			res[r][c] = a[r][c] / b[r][c];
		}
	}
}

void transpoArrays(int** a, int m, int n) {
	int i, j;
	int** res;

	res = array(n, m); //결과 저장하는 배열 생성

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			res[i][j] = a[j][i];
		}
	}
	//printArray(res, n, m, "trans"); //전치행령 구성 결과 출력
	freeArray(res, n, m);
}

void sparseArrays(int** a, int rows, int cols) {
	int** res;
	int count=0; //value(값)의 개수를 세는 변수

	res = array(rows* cols, 3); //결과 저장하는 배열 생성
	res[0][0] = rows;
	res[0][1] = cols;
	
	for (int i = 0; i < rows;i++) {
		for (int j = 0; j < cols; j++) {
			if (a[i][j] != 0) { //값이 0이 아닌 경우
				res[count + 1][0] = i; //행 저장
				res[count + 1][1] = j; //열 저장
				res[count + 1][2] = a[i][j]; //값 저장
				count++;
			}
		}
	}
	res[0][2] = count;
	//printArray(res,count+1,3, "sparse");  //희소행렬 구성 결과 출력
	freeArray(res, rows * cols, 3);
}