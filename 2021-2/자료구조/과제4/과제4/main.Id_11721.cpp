PlatformToolSet=v142:VCToolArchitecture=Native32Bit:VCToolsVersion=14.29.30133:TargetPlatformVersion=10.0.19041.0:
Debug|Win32|D:\단국대학교\2021-2\자료구조\과제4\|
                                                                                                                                                                                                                                                                                                                                              nd(poly1, 1, 1);

	NODELINK *poly2;
	poly2->head = NULL;
	poly2->tail = NULL;

	//f(x) = 6.7x4 + 3.2x ^ 3 − x ^ 2 + x − 2, 여기서 x ∈[−10, 10] 
	append(poly2, 6.7, 4);
	append(poly2, -2, 0);
	append(poly2, -1, 2);
	append(poly2, 3.2, 3);
	append(poly2, 1, 1);

	//NODELINK poly3;
	//poly3.head = NULL;
	//poly3.tail = NULL;

	////f(x) = 6.7x4 + 3.2x ^ 3 − x ^ 2 + x − 2, 여기서 x ∈[−10, 10] 
	//append(&poly3, 6.7, 4);
	//append(&poly3, -2, 0);
	//append(&poly3, -1, 2);
	//append(&poly3, 3.2, 3);
	//append(&poly3, 1, 1);

	//NODELINK poly4;
	//poly4.head = NULL;
	//poly4.tail = NULL;

	////f(x) = 6.7x4 + 3.2x ^ 3 − x ^ 2 + x − 2, 여기서 x ∈[−10, 10] 
	//append(&poly4, 6.7, 4);
	//append(&poly4, -2, 0);
	//append(&poly4, -1, 2);
	//append(&poly4, 3.2, 3);
	//append(&poly4, 1, 1);

	//NODELINK *poly5;
	//poly5->head = NULL;
	//poly5->tail = NULL;

	////f(x) = 6.7x4 + 3.2x ^ 3 − x ^ 2 + x − 2, 여기서 x ∈[−10, 10] 
	//append(poly5, 6.7, 4);
	//append(poly5, -2, 0);
	//append(poly5, -1, 2);
	//append(poly5, 3.2, 3);
	//append(poly5, 1, 1);

	NODELINK *poly_sum= poly_add(poly1,poly2);
	print(poly_sum);
	



	
}