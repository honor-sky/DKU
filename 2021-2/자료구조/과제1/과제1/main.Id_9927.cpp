/*�ʿ��� �Լ�*/
/*
* �迭�� �������� �����ϴ� �Լ�(�迭�� ũ��� main���� �Է¹޾� �Ű������� ����)
* �����޸𸮸� free �ϴ� �Լ�
* �����ϴ� �Լ�
* �y���ϴ� �Լ�
* �������ϴ� �Լ�
* �����ϴ� �Լ�
* main �Լ�
*/

/*�ð����⵵ ��*/
/*
* mxn(mxnxk) ���������� Ű������ �ð����⵵ ����
* ����ð� ����
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "calculate_array.h"

int main(void) {

	int m, n, k, num, g, h;
	int** a, ** b, ** c, ** d, ** res1, ** res2;

	double start, end;

	//printf("(1):���� (2):���� (3):������ (4):����\n");
	//scanf_s("%d", &num);

	//printf("\n�迭�� ũ�� 3��(m,n,k)�� �Է��ϼ���.\n m x n �迭 2��, n x k�迭 1���� ��������ϴ�.\n");
	//scanf_s("%d%d%d", &m, &n, &k); //�迭�� ũ�⸦ �Է¹޾� int�� ���� 3��(m/n/k)�� ����

	m = 2000;
	n = 2000;
	k = 2000;
	g = 2000;
	h = 2000;

    a = array(m, n); //�迭 ����(�������� ��� ������ ���ڰ� 0�̸� �� ��)         
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

	////�迭 ���
	//printArray(a, m, n, "a");
	//printArray(b, m, n, "b");
	//printArray(c, n, k, "c");

	//
	//switch(num) {
	//case 1:
	start = clock();
	plusArrays(res1, a, b, m, n);
    end = clock();
	printf("\n����%f", (double)((end - start) / CLOCKS_PER_SEC));
	//	printArray(res1, m, n, "plus");
	//	break;

	//case 2:
	start = clock();
	minusArrays(res1, a, b, m, n);
	end = clock();
	printf("\n����%f", (double)((end - start) / CLOCKS_PER_SEC));
	//	printArray(res1, m, n, "minus");
	//	break;

	//case 3:
	start = clock();
    divisionArrays(res1, a, b, m, n);
	end = clock();
	printf("\n������%f", (double)((end - start) / CLOCKS_PER_SEC));
	//	printArray(res1, m, n, "division");
	//	break;

	//case 4:
	start = clock();
	multiplyArrays(res2, a, c, m, n, k);
	end = clock();
	printf("\n���ϱ�%f", (double)((end - start) / CLOCKS_PER_SEC));
	//	printArray(res2, m, k, "multiply");
	//	break;
	//
	//
	//}
	
	/*��ġ,��� ��� ���� ���� �迭�� ���� �����߽��ϴ�*/


	//printf("\n��ġ�࿭, ����࿭�� ����ϴ�.\n�迭�� ũ�� 2��(g,h)�� �Է��ϼ���.\n");
	//scanf_s("%d%d", &g,&h);
	
	d = array(g, h);

	for (i = 0; i < g; i++) {
		for (j = 0; j < h; j++) {
			d[i][j] = (rand() % 5);
		}
	}

	//printArray(d, g, h, "d"); 

	start = clock();
	transpoArrays(d, g, h); //��ġ��� ����
	end = clock();
	printf("\n��ġ%f", (double)((end - start) / CLOCKS_PER_SEC));

	start = clock();
	sparseArrays(d, g, h); //������ ����
	end = clock();
	printf("\n���%f", (double)((end - start) / CLOCKS_PER_SEC));

	freeArray(res1,m,n);
	freeArray(res2,m,k);
	freeArray(a,m,n);
	freeArray(b,m,n);
	freeArray(c,m,k);
	freeArray(d,g,h);

	return 0;
	
}