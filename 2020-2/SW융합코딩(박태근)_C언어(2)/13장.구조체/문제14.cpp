/*#include <stdio.h>

struct music {
	char title[20];
	char singer[20];
	char location[50]; //mp3 �� ���� ��ġ
	int type; //�帣
}flie_arr[100];

void add(int add_num);
void print();
char* search();
int add_num = 0; //�迭 �ȿ� ����� ����ü�� ����(���� ����)
int main(void){

	while (1) {
		printf("================");
		printf("1. �߰�\n2. ���\n3. �˻�\n4. ����");
		printf("================");
		int key;
		scanf("%d", &key);
		if (key == 1) { //�� �߰�
			add(add_num);
			add_num++;
		}
		else if (key == 2) {//�� ���

		}
		else if (key == 3) {//�� �˻�

		}
		else { //����
			break;
		}
	}

	return 0;
}
void add(int add_num) { //���� �߰��ϴ� �Լ�
	printf("����:\n");
	gets_s(flie_arr[add_num].title, 20);
	printf("����:\n");
	gets_s(flie_arr[add_num].singer, 20);
	printf("��ġ:\n");
	gets_s(flie_arr[add_num].location, 50);
	printf("�帣:\n");
	gets_s(flie_arr[add_num].type, sizeof(int));
}
void print() { //���� ����ϴ� �Լ�
	printf("����� ���� ������ �����ÿ�\n");
	char title[20];
	gets_s(title, sizeof(title));

}
char* search() {
	return
}*/







