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
	printf("\n%f %f %f", t1 / 5, t2 / 5, t3 / 5);
	

}                                                                                                                                                                                                                                                                                                        'f1;}{\fbimajor\f31503\fbidi \froman\fcharset0\fprq2{\*\panose 02020603050405020304}Times New Roman;}
{\flominor\f31504\fbidi \froman\fcharset0\fprq2{\*\panose 02020603050405020304}Times New Roman;}{\fdbminor\f31505\fbidi \fmodern\fcharset129\fprq2{\*\panose 020b0503020000020004}\'b8\'bc\'c0\'ba \'b0\'ed\'b5\'f1;}
{\fhiminor\f31506\fbidi \fmodern\fcharset129\fprq2{\*\panose 020b0503020000020004}\'b8\'bc\'c0\'ba \'b0\'ed\'b5\'f1;}{\fbiminor\f31507\fbidi \froman\fcharset0\fprq2{\*\panose 02020603050405020304}Times New Roman;}
{\f946\fbidi