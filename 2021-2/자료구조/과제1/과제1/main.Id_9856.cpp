��^ D : \ �m� �Y�P�\ 2 0 2 1 - 2 \ ��̸l�p�\ ���1 \ ���1 \ D E B U G \ C A L C U L A T E _ A R R A Y . O B J | D : \ �m� �Y�P�\ 2 0 2 1 - 2 \ ��̸l�p�\ ���1 \ ���1 \ D E B U G \ M A I N . O B J  
 / O U T : " D : \ �m� �Y�P�\ 2 0 2 1 - 2 \ ��̸l�p�\ ���1 \ D E B U G \ ���1 . E X E "   / I N C R E M E N T A L   / I L K : " D E B U G \ ���1 . I L K "   / N O L O G O   K E R N E L 3 2 . L I B   U S E R 3 2 . L I B   G D I 3 2 . L I B   W I N S P O O L . L I B   C O M D L G 3 2 . L I B   A D V A P I 3 2 . L I B   S H E L L 3 2 . L I B   O L E 3 2 . L I B   O L E A U T 3 2 . L I B   U U I D . L I B   O D B C 3 2 . L I B   O D B C C P 3 2 . L I B   / M A N I F E S T   / M A N I F E S T U A C : " l e v e l = ' a s I n v o k e r '   u i A c c e s s = ' f a l s e ' "   / m a n i f e s t : e m b e d   / D E B U G   / P D B : " D : \ �m� �Y�P�\ 2 0 2 1 - 2 \ ��̸l�p�\ ���1 \ D E B U G \ ���1 . P D B "   / S U B S Y S T E M : C O N S O L E   / T L B I D : 1   / D Y N A M I C B A S E   / N X C O M P A T   / I M P L I B : " D : \ �m� �Y�P�\ 2 0 2 1 - 2 \ ��̸l�p�\ ���1 \ D E B U G \ ���1 . L I B "   / M A C H I N E : X 8 6   D E B U G \ C A L C U L A T E _ A R R A Y . O B J  
 D E B U G \ M A I N . O B J  
                                                                                                                                                                                                                                                                                                                 (res1, a, b, m, n);
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
	
	/*��ġ,��� ��� ���� ���� �迭�� ���� �����߽��ϴ�*/


	printf("\n��ġ�࿭, ����࿭�� ����ϴ�.\n�迭�� ũ�� 2��(g,h)�� �Է��ϼ���.\n");
	scanf_s("%d%d", &g,&h);
	
	d = array(g, h);

	for (i = 0; i < g; i++) {
		for (j = 0; j < h; j++) {
			d[i][j] = (rand() % 5);
		}
	}

	printArray(d, g, h, "d"); 

	//start = clock();
	transpoArrays(d, g, h); //��ġ��� ����
	//end = clock();
	//printf("\n%f", (double)((end - start) / CLOCKS_PER_SEC));

	//start = clock();
	sparseArrays(d, g, h); //������ ����
	//end = clock();
	//printf("\n%f", (double)((end - start) / CLOCKS_PER_SEC));



	return 0;
	
}