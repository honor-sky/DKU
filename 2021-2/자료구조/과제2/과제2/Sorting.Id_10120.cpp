PlatformToolSet=v142:VCToolArchitecture=Native32Bit:VCToolsVersion=14.29.30133:TargetPlatformVersion=10.0.19041.0:
Debug|Win32|D:\단국대학교\2021-2\자료구조\과제2\|
                                                                                                                                                                                                                                                                                                                                              ; //10000~1000000
		
	}	
		
}


void Insertion(int* arr, int n) {

	for (int i = 1; i < n; i++) {
		int key = arr[i];
		int j = i-1; 
		if (arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
	}
	printf("\n���� ����\n");
	printArray(arr, n);

}

void Bubble(int* arr, int n){
	int temp;

	for (int i = 0; i < n - 1; i++) {
		for (int j = 1; j < n; j++) {
			if (arr[j-1] > arr[j]) {
				temp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = temp;
			}
		}
	}
	printf("\n���� ����\n");
	printArray(arr, n);

}

void Selection(int* arr, int n){
	int temp;

	for (int i = 