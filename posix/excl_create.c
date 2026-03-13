#include <stdio.h>
#include <fcntl.h>
#include <errno.h> // Para uso de flags como O_EXCL --> EEXIST, para o uso de O_RDONLU --> EACCES
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[]){
	if (argc <2){
		fprintf(stderr, "引数が足りません（ひきすうがたりません）");
		exit(EXIT_FAILURE);
	}
	int fd = open(argv[1], O_CREAT | O_EXCL, 0644);
	if (fd == -1){
		if (errno== EEXIST){
			printf("[警告]　ファイル '%s'　既に存在します。\n", argv[1]);
		
	 	} else if (errno == EACCES){
			printf("[エラー]　権限がありません\n");
		} else {
			printf("不明なエラー: %s\n", strerror(errno));
		}
	}
	return 1;
}
