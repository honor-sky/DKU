#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(void) {

	char c;

	while (1) {
		printf("���ڸ� �Է��Ͻÿ�:");
		c = getchar();  //�ι�°���� ȣ���� �Ұ���...
		//���ۿ��� \n�� �� �־ �ǳ� �ٴ� �Ŵ�..��, �ٹٲ��� ��������� ��
		char c2 = fgetc(stdin); //���1) ���ۿ� ���Ҵ� \n���ڸ� ���ο� char�� c2�� ������ ���� ����

		if (isupper(c)) { //���̸�
			c = tolower(c);
			putchar(c);
			printf("\n");
		}
		else if (islower(c)) {
			c = toupper(c);
			putchar(c);
			printf("\n");
		}
		else if (c == '.') {
			break;
		}
		else {
			printf("���!");
		}
		//c = getchar(); //���2) �����ۿ� ���Ҵ� \n�� c�� ������ ���� ����
	}

	return 0;
}





