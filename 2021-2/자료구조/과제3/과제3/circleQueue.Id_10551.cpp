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
/*����ť�� �� á���� Ȯ��*/