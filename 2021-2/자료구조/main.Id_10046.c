PlatformToolSet=v142:VCToolArchitecture=Native32Bit:VCToolsVersion=14.29.30133:TargetPlatformVersion=10.0.19041.0:
Debug|Win32|D:\단국대학교\2021-2\자료구조\과제3\|
                                                                                                                                                                                                                                                                                                                                              �ť���� ���� ��(������� �� ���Ұ� ����)*/
void dequeue(circle_Que que) {
	que.queue[que.front] = NULL;
	que.front = (que.front + 1) % 10;
	que.lastOperation = false;
}
/*����ť�� ������� Ȯ��*/
bool isEmpty(circle_Que que) {
	if (que.lastOperation == true) {
		printf("����ť�� ������ �ֽ��ϴ�.");
	}
	else {
		printf("����ť�� �� á���ϴ�.");
	}
}
/*����ť�� �� á���� Ȯ��*/                                                                                                                   
	res2 = array(m, k);

	int i, j;

	for (i = 0; i < m; i++) {            
		for (j = 0; j < n; j++) {
			a[i][j] = (rand() % 10) + 1;
			b[i][j] = (rand() % 10) + 1;
		}
	}

	for (i = 0; i < n; i++) {          
		for (j = 0; j < k; j++) {
			c[i][j] = (rand() % 5) + 1;
		}
	}

	//배열 출력
	printArray(a, m, n, "a");
	printArray(b, m, n, "b");
	printArray(c, n, k, "c");


	switch(num) {
	case 1:
                //start = clock();
		plusArrays(res1, a, b, m, n);
                //end = clock();
		printArray(res1, m, n, "plus");
		break;

	case 2:
		minusArrays(res1, a, b, m, n);
		printArray(res1, m, n, "minus");
		break;

	case 3:
		divisionArrays(res1, a, b, m, n);
		printArray(res1, m, n, "division");
		break;

	case 4:
		multiplyArrays(res2, a, c, m, n, k);
		printArray(res2, m, k, "multiply");
		break;
	
	
	}
        //printf("\n%f", (double)((end - start) /CLOCKS_PER_SEC ));

	
       printf("\n전치행열, 희소행열을 만듭니다.\n배열의 크기 2개(g,h)를 입력하세요.\n");
	scanf("%d%d", &g,&h);
	
	d = array(g, h);

	for (i = 0; i < g; i++) {
		for (j = 0; j < h; j++) {
			d[i][j] = (rand() % 5);
		}
	}

	printArray(d, g, h, "d");
	transpoArrays(d, g, h);
	sparseArrays(d, g, h);

	return 0;
	
}
