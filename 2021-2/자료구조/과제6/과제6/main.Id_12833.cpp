  BFS.cpp
  main.cpp
  코드를 생성하고 있습니다...
  과제6.vcxproj -> D:\단국대학교\2021-2\자료구조\과제6\Debug\과제6.exe
                                                                                                                                                                                                                                                                                                                                                                     ? ???? label
	int n,m;

	visited[1] = 1; //ù???? ?湮
	while (count < SIZE)
	{
		int min = 100; //min?? ?????? ?????? ????
		for (n = 1; n <= SIZE; n++)
		{
			for (m = 1; m <= SIZE; m++)
			{
				if (G_matrix[n][m] < min)
				{
					if (visited[n] != 0) //?湮???? ???? ???????? true
					{
						min = G_matrix[n][m];
						u = n;
						v = m;
					}
				}
			}
		}
		//if node is not visited
		if (visited[m] == 0) 
		{
			printf("\n%d to %d  weight=%d", n, m, min); //?湮?? ?????? ????ġ ????
			cost += min;
			count++;
		}
		visited[m] = 1; //?湮 ?? 1?? label
		// initialize with maximum value you can also use any other value
		//cost[a][b] = cost[b][a] = 1000;
	}
	printf("\nminimum cost is %d", cost); //?ּ? ???? ????
	printf("\nnumber of node is %d", count); //???? ???? ????
	printf("\nnumber of edge is %d", count-1); //???? ???? ????

	////???? ?ּ? ????ġ ????      //???? ????ġ?? ???? ó???? ???? ????
	//for (n = 0; n < SIZE; n++) {
	//	for (m = 0; m < SIZE; m++) {
	//		if (G_matrix[n][m] != NULL && G_matrix[n][m] != 0) {
	//			if (G_matrix[n][m] < min) {
	//				min = G_matrix[n][m];
	//				u = n;
	//				v = m;
	//			}
	//		}
	//	}
	//	S_matrix[u][v] = min;
	//	S_matrix[v][u] = min;
	//	uu = u;
	//	vv = v;
	//	cost += min;
	//	count++;
	//}
	////?? ??????
	//while (count == 7) { //???? ???? ?߰??ϸ? ?Ϸ?
	//	min = 100;
	//	//?ּ? ????ġ ????
	//	for (m = 0; m < SIZE; m++) {
	//		if (G_matrix[uu][m] != NULL) {
	//			if (G_matrix[uu][m] < min) {  //?տ??? ?ߴ? ?????? ????
	//				min = G_matrix[uu][m];
	//				u = n;
	//				v = m;
	//			}
	//		}
	//	}
	//	for (m = 0; m < SIZE; m++) {
	//		if (G_matrix[vv][m] != NULL) {
	//			if (G_matrix[vv][m] < min) {
	//				min = G_matrix[vv][m];
	//				u = n;
	//				v = m;
	//			}
	//		}
	//	}
	//	//cycle???? Ȯ??
	//	

	//	//???? min???? ?߰?
	//	S_matrix[u][v] = min;
	//	S_matrix[v][u] = min;
	//	uu = u;
	//	vv = v;
	//	cost += min;
	//	count++;

	//}
	
	
	return 0;
}