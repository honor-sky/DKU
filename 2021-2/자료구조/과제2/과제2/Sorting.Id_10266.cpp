
int* array(int n);
void freeArray(int* arr);
void mrand(int* arr, int n);
void Insertion(int* arr, int n);
void Bubble(int* arr, int n);
void Selection(int* arr, int n);
void printArray(int* arr, int n);

                                                                                                                                                                                                                                                                                                         	
		
}


void Insertion(int* arr, int n) {

	for (int i = 1; i < n; i++) {
		int key = arr[i];
		//int j = i-1; 
		for (int j = i - 1; j >= 0; j--) {
			if (arr[j] > key ) {
				arr[j+1] = arr[j];
				arr[j] = key;
			}
			
		}
		
	}
	printf("삽입 정렬\n");
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
	printf("버블 정렬\n");
	printArray(arr, n);

}

void Selection(int* arr, int n){
	int temp;

	for (int i = 0; i < n-1;i++){
		int least = i;
		for (int j = i+1; j < n; j++) {
			if ( arr[j]< arr[least]) {
				least = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[least];
		arr[least] = temp;

	}
	printf("선택 정렬\n");
	printArray(arr, n);
}         