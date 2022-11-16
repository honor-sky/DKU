#include<stdio.h>
#include "common.h"

multiplyTwoArrays( int **res, int **a, int **b, int m, int n, int q){
	int r, c, k;
	int sum;

	for(r=0; r<m; r++)
	   for(c=0; c<q; c++){
		   sum = 0;
		   for(k=0; k<n; k++)
		       sum += a[r][k] + b[k][c];
		   res[r][c] = sum;
    }
}


void main(){
	int m = 10, n=5, q = 6;
	int r, c;
	int **a, **b, **res;  //2���� �迭�� ����� ������ ���� �����͸� ���� 
						  
	                      //�迭�� ũ�⸦ ���� �Ҵ� �������̱� ������ �̷��� �Ѵ�.
	 
	a = array( m, n);         //�迭1 //�迭 ����� �ּҸ� ��ȯ//�� ���Ұ��� ������������ �͵� ����
	b = array( n, q);         //�迭2
    res = array( m, q);       //��� �迭

    /* assign some values to the arrays */ 
	for(r=0; r<m; r++)              //�迭1 ����
	   for(c=0; c<n; c++)
	       a[r][c] = rand()%10;

	for(r=0; r<n; r++)             //�迭2 ����
	   for(c=0; c<q; c++)
	       b[r][c] = rand()%5;

	/* multiply a[][] and b[][] */
	multiplyTwoArrays( res, a, b, m, n, q);
	printArray( res, m, q, "C");

}
