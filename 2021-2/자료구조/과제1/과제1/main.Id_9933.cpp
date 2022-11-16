/*필요한 함수*/
/*
* 배열을 동적으로 생성하는 함수(배열의 크기는 main에서 입력받아 매개변수로 전달)
* 동적메모리를 free 하는 함수
* 덧셈하는 함수
* 뻴셈하는 함수
* 나눗셈하는 함수
* 곱셈하는 함수
* main 함수
*/

/*시간복잡도 평가*/
/*
* mxn(mxnxk) 점진적으로 키워가며 시간복잡도 관찰
* 실행시간 측정
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "calculate_array.h"

int main(void) {

	int m, n, k, num, g, h;
	int** a, ** b, ** c, ** d, ** res1, ** res2;

	double start, end;

	//printf("(1):덧셈 (2):뺄셈 (3):나눗셈 (4):곱셈\n");
	//scanf_s("%d", &num);

	//printf("\n배열의 크기 3개(m,n,k)를 입력하세요.\n m x n 배열 2개, n x k배열 1개가 만들어집니다.\n");
	//scanf_s("%d%d%d", &m, &n, &k); //배열의 크기를 입력받아 int형 변수 3개(m/n/k)에 저장

	m = 2000;
	n = 2000;
	k = 2000;
	g = 2000;
	h = 2000;

    a = array(m, n); //배열 생성(나눗셈의 경우 나누는 숫자가 0이면 안 됨)         
	b = array(m, n);
	res1 = array(m, n);

	c = array(n, k);
	res2 = array(m, k);

	int i, j;

	for (i = 0; i < m; i++) {            
		for (j = 0; j < n; j++) {
			a[i][j] = (rand() % 10);
			b[i][j] = (rand() % 10) + 1;
		}
	}

	for (i = 0; i < n; i++) {          
		for (j = 0; j < k; j++) {
			c[i][j] = (rand() % 5);
		}
	}

	////배열 출력
	//printArray(a, m, n, "a");
	//printArray(b, m, n, "b");
	//printArray(c, n, k, "c");

	//
	//switch(num) {
	//case 1:
	start = clock();
	plusArrays(res1, a, b, m, n);
    end = clock();
	printf("\n덧셈%f", (double)((end - start) / CLOCKS_PER_SEC));
	//	printArray(res1, m, n, "plus");
	//	break;

	//case 2:
	start = clock();
	minusArrays(res1, a, b, m, n);
	end = clock();
	printf("\n뺄셈%f", (double)((end - start) / CLOCKS_PER_SEC));
	//	printArray(res1, m, n, "minus");
	//	break;

	//case 3:
	start = clock();
    divisionArrays(res1, a, b, m, n);
	end = clock();
	printf("\n나누기%f", (double)((end - start) / CLOCKS_PER_SEC));
	//	printArray(res1, m, n, "division");
	//	break;

	//case 4:
	start = clock();
	multiplyArrays(res2, a, c, m, n, k);
	end = clock();
	printf("\n곱하기%f", (double)((end - start) / CLOCKS_PER_SEC));
	//	printArray(res2, m, k, "multiply");
	//	break;
	//
	//
	//}
	
	/*전치,희소 행렬 구성 위한 배열을 따로 생성했습니다*/


	//printf("\n전치행열, 희소행열을 만듭니다.\n배열의 크기 2개(g,h)를 입력하세요.\n");
	//scanf_s("%d%d", &g,&h);
	
	d = array(g, h);

	for (i = 0; i < g; i++) {
		for (j = 0; j < h; j++) {
			d[i][j] = (rand() % 5);
		}
	}

	//printArray(d, g, h, "d"); 

	start = clock();
	transpoArrays(d, g, h); //전치행렬 구성
	end = clock();
	printf("\n전치%f", (double)((end - start) / CLOCKS_PER_SEC));

	start = clock();
	sparseArrays(d, g, h); //희소행렬 구성
	end = clock();
	printf("\n희소%f", (double)((end - start) / CLOCKS_PER_SEC));

	freeArray(res1,m,n);
	freeArray(res2,m,k);
	freeArray(a,m,n);
	freeArray(b,m,n);
	freeArray(c,m,k);
	freeArray(d,g,h);

	return 0;
	
}