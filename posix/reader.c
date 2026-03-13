#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char*argv[]){
	if (argc<2){
		fprintf(stderr,"引数が足りません\n");
		exit(EXIT_FAILURE);
	}

	char buff[1024];

	int  fd = open(argv[1], O_RDONLY);
	if  (fd == -1){
		perror("ファイルを開く際にエラーが発生しました\n");
		exit(EXIT_FAILURE);
	memset(buff, 0, sizeof(buff));
	}
	ssize_t leitor = read(fd, buff, sizeof(buff));
	if (leitor == -1){
		perror("ファイルを読む際にエラーが発生しました\n");
		exit(EXIT_FAILURE);
	}

	printf("%s\n", buff);
	close(fd);
}
