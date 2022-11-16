#include <stdlib.h>
#include <stdio.h>
#include "calculate_array.h"

int** array(int rows, int cols) {  //2���� �ڷᱸ�� ��������
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

	res = array(n, m); //��� �����ϴ� �迭 ����

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			res[i][j] = a[j][i];
		}
	}
	//printArray(res, n, m, "trans"); //��ġ��� ���� ��� ���
	freeArray(res, n, m);
}

void sparseArrays(int** a, int rows, int cols) {
	int** res;
	int count=0; //value(��)�� ������ ���� ����

	res = array(rows* cols, 3); //��� �����ϴ� �迭 ����
	res[0][0] = rows;
	res[0][1] = cols;
	
	for (int i = 0; i < rows;i++) {
		for (int j = 0; j < cols; j++) {
			if (a[i][j] != 0) { //���� 0�� �ƴ� ���
				res[count + 1][0] = i; //�� ����
				res[count + 1][1] = j; //�� ����
				res[count + 1][2] = a[i][j]; //�� ����
				count++;
			}
		}
	}
	res[0][2] = count;
	//printArray(res,count+1,3, "sparse");  //������ ���� ��� ���
	freeArray(res, rows * cols, 3);
}