/*main code for sorting/kyungmin Kim/2021.10.09*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Sorting.h"

int main() {

	double start, end;
	double t1=0, t2=0, t3=0;
	int* a;
	int arr_size = 130000;

	for (int i = 0; i < 5; i++) {
		a = array(arr_size);

		start = clock();
		Insertion(a, arr_size);
		end = clock();
		t1 += (double)((end - start) / CLOCKS_PER_SEC);
		

		start = clock();
		Bubble(a, arr_size);
		end = clock();
		t2 += (double)((end - start) / CLOCKS_PER_SEC);
		

		start = clock();
		Selection(a, arr_size);
		end = clock();
		t3 += (double)((end - start) / CLOCKS_PER_SEC);

		freeArray(a);
	}
	printf("\n%f %f %f", t1 / 