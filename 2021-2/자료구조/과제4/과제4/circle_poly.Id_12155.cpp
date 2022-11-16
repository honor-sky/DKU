#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "poly.h"

typedef struct NODE {
	double coef;
	int expon;
	struct NODE* link;
}NODE;

typedef struct NODELINK { 
	struct NODE* head;
	struct NODE* tail;
}NODELINK;


int main() {

	NODELINK poly1;
	poly1.head = NULL;
	poly1.tail = NULL;

	//f(x) = 6.7x^4 + 3.2x ^ 3 − x ^ 2 + x − 2
	append(&poly1, 6.7,4);
	append(&poly1, 3.2, 3);
	append(&poly1, -1, 2);
	append(&poly1, 1, 1);
	append(&poly1, -2, 0);
	//print(&poly1);

	NODELINK poly2;
	poly2.head = NULL;
	poly2.tail = NULL;

	//f(x) = x^5 + 2.5x -3x^2 + 4.1 + 2x^7
	append(&poly2, 1,5);
	append(&poly2, 2.5,1);
	append(&poly2, -3, 2);
	append(&poly2, 4.1, 0);
	append(&poly2, 2, 7);
	//print(&poly2);

	NODELINK poly3;
	poly3.head = NULL;
	poly3.tail = NULL;

	////f(x) = x^8 + x^6 + x^5 + x^4 + x^3 + x + 2
	append(&poly3, 1,8);
	append(&poly3, 1,6);
	append(&poly3, 1,5);
	append(&poly3, 1,4);
	append(&poly3, 1, 3);
	append(&poly3, 1, 1);
	append(&poly3, 2, 0);
	//print(&poly3);

	NODELINK poly4;
	poly4.head = NULL;
	poly4.tail = NULL;

	////f(x) = -x + 3x^5 + 2.7x^3 - 4x^2 -5.5
	append(&poly4, -1,1);
	append(&poly4, 3,5);
	append(&poly4, 2.7,3);
	append(&poly4, -4,2);
	append(&poly4, -5.5,0);
	//print(&poly4);

	NODELINK poly5;
	poly5.head = NULL;
	poly5.tail = NULL;

	////f(x) = 10x^2 + 2.4x^3 -1.5 - x - 3.6x^5
	append(&poly5, 10,2);
	append(&poly5, 2.4,3);
	append(&poly5, -1.5,0);
	append(&poly5, -1,1);
	append(&poly5, -3.6,5);
	//print(&poly5);


	NODELINK *poly_sum= poly_add(&poly1,&poly2);
	print(poly_sum);

	NODELINK* poly_re = poly_minu(&poly3, &poly4);
	print(poly_re);


	
}                                                                                                                                                                                                                                                                                                                                            D����R��.�Ʒ�&F��q�Ai��	��|��k�D{�рN���(Lf�\q���-pxst[�(�V�Dx��Tz�|�4�G����ph���ը�K9A��XJ����2�Z,wۚv�
F/W4@E��-��\4�ڔ�MO �b�Si�u}�qVO[!����h�uM@#�nx�J*c\B� c.C����K_fx�����L2P�{�(����Ҥ U�e����>���\���Y�u�4zB�[�:�lqi}7P�Ǎu	]���,��X�V�~�,�2X�ǌM�VMU����Wb{T��d��R{����4s�&Y!�2��E�����t�@E�s�A:
�I�]���=�*�My=0��	�Q�B��_���J�(u\���XƊ�cC_�������QE�!�%�uKm!����ƺ��$p}�\/ԍO��X`4f��b�ل�^Q��H�㬦��Q�dh ��,q�L� 9�jV�*�(q��3�1�b�I8����Ò%1�	q!��⤚pU�SX�C��z�b4�&�c�e@�(�/I�֛lӿ	m��q8Ta���.\�!����*\�E�2���6@�Y�;e��¶��,v2.�2d�wQ���B��p��Si[B�]�W�f1���z�ކo��l-�-�x(5��~�������&�G��pS�{�OK��Y�s��.�,ƣn��k�cl)4� ��7�Ẍ́�gx3�E`��d�&R��Xh�.$��3��\\k
��Vb�����x��1 �Y��z���7k�Ă�qI	�qF5�� Z���I0�Z��5S�g\3������D/C���p��$�p�>�a����Xl���sj%�%p�N�5c�GZ(�0N����x��%�uD�+.��>{qs�	ή��oE�ʄ)��ޮf!oS)Z\�����:nsV�#��