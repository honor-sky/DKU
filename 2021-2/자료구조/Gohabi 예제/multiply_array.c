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
	int **a, **b, **res;  //2차원 배열을 만들기 때문에 이중 포인터를 쓴다 
						  
	                      //배열의 크기를 동적 할당 받을것이기 때문에 이렇게 한다.
	 
	a = array( m, n);         //배열1 //배열 덩어리의 주소를 반환//각 원소값이 포인터형식인 것도 유지
	b = array( n, q);         //배열2
    res = array( m, q);       //결과 배열

    /* assign some values to the arrays */ 
	for(r=0; r<m; r++)              //배열1 셋팅
	   for(c=0; c<n; c++)
	       a[r][c] = rand()%10;

	for(r=0; r<n; r++)             //배열2 셋팅
	   for(c=0; c<q; c++)
	       b[r][c] = rand()%5;

	/* multiply a[][] and b[][] */
	multiplyTwoArrays( res, a, b, m, n, q);
	printArray( res, m, q, "C");

}
