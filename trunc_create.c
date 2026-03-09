#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char* argv[]){
	if (argc < 2){
		fprintf(stderr, "引数が足りません\n");
	}
	int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1){
		fprintf(stderr, "ファイルを開く際にえらーが発生しました\n");
	}
	close(fd);
}
