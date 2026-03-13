#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define PIPE_BUF_SIZE 100

int main(){
	int pipefd[2];
	pid_t pid;
	char buffer[PIPE_BUF_SIZE];
	
	
	if (pipe(pipefd)==-1){
		perror("ファイルを作成する際に失敗しました");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid==-1){
		perror("Erro no fork");
		exit(EXIT_FAILURE);
	}
	
	if (pid==0){
		close(pipefd[0]);
