#include <stdio.h>
#include <stdlib.h>

char* get_word() {
	char* s = (char*)malloc(sizeof(char) * 50);
	if (s == NULL) {
		printf("�޸� �Ҵ� ����");
		exit(1);
	}
	printf("�ܾ �Է��Ͻÿ�:(�ִ� 50����):");
	scanf("%s", s);

	return s;
}
int main(void) {
	//�ܾ� �Է� �޴� ���� �޸� ���� �Լ�
	char* word = get_word();
	//���
	printf("���� �޸𸮿� ����� �ܾ�� %s�Դϴ�.", word);


	return 0;
}








