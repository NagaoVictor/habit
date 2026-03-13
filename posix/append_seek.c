#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>


int main(int argc, char* argv[]){
	int fd;
	if (strcmp(argv[1], "append")==0){
		fd = open(argv[1], O_RDWR | O_APPEND);
		if(fd == -1){
			fprintf(stderr, "追記エラー : %s\n", strerror(errno));
		}
	} else if (strcmp(argv[1], "trunc")==0){
		fd open(argv[1], O_RDWR | O_TRUNC);
		if(fd == -1){
			fprintf(stderr, "初期化エラー : %s\n　", strerror(errno));
	}
	





}

