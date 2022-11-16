/*Simple customizing shell project, Kyungmin Kim, 2021/11/02, keung903@naver.com*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <dirent.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#define COMM_SIZE 1024
#define TOK_SIZE 50


//��ɾ� ����
int parsing(char* tokens[], char* command) {

	char delim[] = " \n";
	int token_count = 0;

	tokens[0] = strtok(command, delim);
	while (tokens[token_count] != NULL) {
		token_count++;// �ڸ� ���ڿ��� ������ ���� ������ �ݺ�
		tokens[token_count] = strtok(NULL, delim);      // ���� ���ڿ��� �߶� �����͸� ��ȯ
	}

	return token_count;
}

//background ���� //�ڽ��� �ڽĴ�� �θ�� �θ��� ����
void back_exe(char* tokens[]) {

	int child;

	if ((child = fork()) == 0) {
		if ((child = fork()) == 0) { //�ڽ� ���μ���
			execvp(tokens[0], tokens);
		}
	}

}

void cmd_help() {
	
	printf("/******Simple Shell******/\n");
	printf("You can use it just as the conventional shell\n");
	printf("help		: show this help\n");
	printf("exit		: exit this shell\n");
	printf("ps		: exit this shell\n");
	printf("ls		: show all files\n");
	//printf("cd		: change directory\n");
	//printf("ls-l		: show all files and details\n");
}

void cmd_ps() {
	DIR* dir;    
	FILE* fp;
	char status[100];

	struct dirent* file;        // �� ������ ����Ű�� ����ü
	struct stat fileStat;          // ������ ����

	int pid;                       //�� ���μ��� pid
	char cmdLine[256];
	char tempPath[256];

	printf("[pid]   directory\n");
	dir = opendir("/proc");

	while ((file = readdir(dir)) != NULL) {
		lstat(file->d_name, &fileStat); //���� ���� ��ȯ

		if (!S_ISDIR(fileStat.st_mode))           //���丮���� Ȯ��
			continue;  //�ƴϸ� ��������                          
															 

		pid = atoi(file->d_name); //���μ����� �ڽ��� pid�� ���丮�� ���� 
		if (pid <= 0) continue;   //���μ��� �ƴϸ� ��������                 

		sprintf(tempPath, "/proc/%d/cmdline", pid); //cmdline : ���μ����� �̸�

		fp = fopen(temp_path, "r"); //tempPath�̸��� ���� ����
		memset(cmdLine, '\0', sizeof(cmdLine)); 
		fgets(cmdLine, 256, fp);
		fclose(srcFp);

		if (cmdLine[0] != '\0')
			printf("[%d]\t%s\n", pid, cmdLine);
															
	}
	closedir(dir); //dir �ݱ�
}



//��ɾ� ����
bool comm_exe(char* command) {

	char *tokens[TOK_SIZE];
	int i, child, status;
	bool back = false;

	int token_count = parsing(tokens, command);

	//exit����
	if (strcmp(tokens[0], "exit\n") == 0) {
		return false;
	}
    //help ����
	if (strcmp(tokens[0], "help\n") == 0) { 
		cmd_help();
		return true;
	}
	//ps ����
	if (strcmp(tokens[0], "ps\n") == 0) {

	    return true;
    }
	//ls ����
	//if (strcmp(tokens[0], "ls\n") == 0) {

	//	DIR* dir = NULL;
	//	struct dirent* file = NULL;

	//	if ((dir = opendir(get_current_dir_name())) == NULL){
	//			printf("current directory error\n");
	//			exit(1);
	//	}
	//	while ((file = readdir(dir)) != NULL)
	//	{
	//			printf("%s\n", file->d_name);
	//	}
	//	closedir(dir);

	//    return true;
 //   }

	child = fork();
	if (child == 0) {//�ڽ� ���μ��� ����
		//background �������� Ȯ��
		for (i = 0; i < token_count; i++) {
			if (strcmp(tokens[i], "&") == 0) {
				back = true;
				back_exe(tokens);
				break;
			}
		}
		//background ���� �ƴ�
		execvp(tokens[0], tokens);

	}
	else { //�θ� ���μ��� ����
		/*�ڽ� ���μ����� ��� ���μ����� �Ǵ� ���� �����ϱ� ���� ������ �ڽ� ���μ��� ���� ����*/
		waitpid(pid, &status, 0);

	}

	return true;

}

//��ɾ �Է¹���
int main() {

	char command[COMM_SIZE];
	while (1) {

		//��ɾ� �Է¹ޱ�
		printf("%s$ ", get_current_dir_name());
		fgets(command, sizeof(command)-1, stdin);
		if (command == NULL) {
			break;
		}
		else {
			bool re = comm_exe(command);
			if (re == false) { 
				break; 
			}
		}

	}
	return 0;
}

//redirection
//void redirection(int argc, char* argv[]) {
	int i;
	int fd;
	for (i = 0; i < argc; i++) {
		if (strcmp(argv[i],">")==0) { //redirection ó��
			fd = open(argv[i + 1], O_RDWR | O_CREAT | O_TRUNC, 0641);
			dup2(fd, STDOUT_FILENO); //������ �͹̳ο� ��µǴ°� �ƴ϶� ���� ���� ���Ͽ� ���
		}
	}
//	return;
//}
