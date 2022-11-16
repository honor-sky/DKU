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


//명령어 분해
int parsing(char* tokens[], char* command) {

	char delim[] = " \n";
	int token_count = 0;

	tokens[0] = strtok(command, delim);
	while (tokens[token_count] != NULL) {
		token_count++;// 자른 문자열이 나오지 않을 때까지 반복
		tokens[token_count] = strtok(NULL, delim);      // 다음 문자열을 잘라서 포인터를 반환
	}

	return token_count;
}

//background 수행 //자식은 자식대로 부모는 부모대로 수행
void back_exe(char* tokens[]) {

	int child;

	if ((child = fork()) == 0) {
		if ((child = fork()) == 0) { //자식 프로세스
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

	struct dirent* file;        // 각 파일을 가르키는 구조체
	struct stat fileStat;          // 파일의 정보

	int pid;                       //각 프로세의 pid
	char cmdLine[256];
	char tempPath[256];

	printf("[pid]   directory\n");
	dir = opendir("/proc");

	while ((file = readdir(dir)) != NULL) {
		lstat(file->d_name, &fileStat); //파일 정보 반환

		if (!S_ISDIR(fileStat.st_mode))           //디렉토리인지 확인
			continue;  //아니면 다음으로                          
															 

		pid = atoi(file->d_name); //프로세스는 자신의 pid로 디렉토리를 만듬 
		if (pid <= 0) continue;   //프로세스 아니면 다음으로                 

		sprintf(tempPath, "/proc/%d/cmdline", pid); //cmdline : 프로세스의 이름

		fp = fopen(temp_path, "r"); //tempPath이름의 파일 열기
		memset(cmdLine, '\0', sizeof(cmdLine)); 
		fgets(cmdLine, 256, fp);
		fclose(srcFp);

		if (cmdLine[0] != '\0')
			printf("[%d]\t%s\n", pid, cmdLine);
															
	}
	closedir(dir); //dir 닫기
}



//명령어 수행
bool comm_exe(char* command) {

	char *tokens[TOK_SIZE];
	int i, child, status;
	bool back = false;

	int token_count = parsing(tokens, command);

	//exit실행
	if (strcmp(tokens[0], "exit\n") == 0) {
		return false;
	}
    //help 실행
	if (strcmp(tokens[0], "help\n") == 0) { 
		cmd_help();
		return true;
	}
	//ps 실행
	if (strcmp(tokens[0], "ps\n") == 0) {

	    return true;
    }
	//ls 실행
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
	if (child == 0) {//자식 프로세스 진행
		//background 실행인지 확인
		for (i = 0; i < token_count; i++) {
			if (strcmp(tokens[i], "&") == 0) {
				back = true;
				back_exe(tokens);
				break;
			}
		}
		//background 실행 아님
		execvp(tokens[0], tokens);

	}
	else { //부모 프로세스 진행
		/*자식 프로세스가 고아 프로세스가 되는 것을 방지하기 위해 무조건 자식 프로세스 먼저 실행*/
		waitpid(pid, &status, 0);

	}

	return true;

}

//명령어를 입력받음
int main() {

	char command[COMM_SIZE];
	while (1) {

		//명령어 입력받기
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
		if (strcmp(argv[i],">")==0) { //redirection 처리
			fd = open(argv[i + 1], O_RDWR | O_CREAT | O_TRUNC, 0641);
			dup2(fd, STDOUT_FILENO); //앞으로 터미널에 출력되는게 아니라 새로 만든 파일에 출력
		}
	}
//	return;
//}
