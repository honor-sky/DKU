typedef struct TERM;
void append(TERM* poly, double coef, int expon, int arr);
void sort(TERM* poly, int n);
void print(TERM* poly, int n);
void poly_add(TERM* a, int asize, TERM* b, int bsize, TERM* c);
void poly_minu(TERM* a, int asize, TERM* b, int bsize, TERM* c);
                                                                                                                                                                                                                                             f(x) = x^8 + x^6 + x^5 + x^4 + x^3 + x + 2
	append(poly3, 1, 8, 0);
	append(poly3, 1, 6, 1);
	append(poly3, 1, 5, 2);
	append(poly3, 1, 4, 3);
	append(poly3, 1, 3, 4);
	append(poly3, 1, 1, 5);
	append(poly3, 2, 0, 6);
	print(poly3,7);	
	
	TERM poly4[5];
	////f(x) = -x + 3x^5 + 2.7x^3 - 4x^2 -5.5
	append(poly4, -1, 1,0);
	append(poly4, 3, 5,1);
	append(poly4, 2.7, 3,2);
	append(poly4, -4, 2,3);
	append(poly4, -5.5, 0,4);
	print(poly4,5);
	

	TERM poly5[5];
	////f(x) = 10x^2 + 2.4x^3 -1.5 - x - 3.6x^5
	append(poly5, 10, 2,0);
	append(poly5, 2.4, 3,1);
	append(poly5, -1.5, 0,2);
	append(poly5, -1, 1,3);
	append(poly5, -3.6, 5,4);
	print(poly5,5);

	//printf("%d", sizeof(poly1)/sizeof(TERM));
	TERM result[6];

	poly_add(poly1,5 ,poly2,5 ,result);
	print(result, 6);

}                                                                                                                                                                                                                       )->expon) {
			(c + count)->coef = (a + i)->coef;
			(c + count)->expon = (a + i)->expon;
			i++;
			j++;
			count++;
		}
		else if (i== asize) {
			(c + count)->coef = (b + j)->coef;
			(c + count)->expon = (b + j)->expon;
			j++;
			count++;
		}
		else if (j==bsize){
			(c + count)->coef = (a + i)->coef;
			(c + count)->expon = (a + i)->expon;
			i++;
			count++;
		}
						
	}
}
//
/////*���׽��� ����*/
//TERM* poly_minu(TERM* a, TERM* b, int n) 