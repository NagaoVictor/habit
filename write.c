#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char*argv[]){
/*	if (argc ==  2){
		int fd_dest = open(argv[3], O_WRONLY);
		if (fd_dest==-1){
			perror("Erro ao usar o arquivo de destino\n");
			exit(EXIT_FAILURE);
			}
	} else if (argc ==  3){
		int fd_dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd_dest == -1){
			perror("Erro ao usar o arquivo de destino\n");
			exit(EXIT_FAILURE);
			}
	} else if (argc < 2 || argc > 3){
		fprintf(stderr, "Uso <Caminho1> ou/e <Caminho2>", argv[0]);
		exit(EXIT_FAILURE);
	} else {
		perror("Algo aconteceu\n");
		exit(EXIT_FAILURE);

	} */
	
	int fd_dest = open(argv[2], O_WRONLY);
	char buff[1024];
	
	int  fd_ori = open(argv[1], O_RDONLY);
	if  (fd_ori == -1){
		perror("ファイルを開く際にエラーが発生しました\n");
		exit(EXIT_FAILURE);
	memset(buff, 0, sizeof(buff));
	}	
	ssize_t leitor = read(fd_ori, buff, sizeof(buff));
	if (leitor == -1){
		perror("ファイルを読む際にエラーが発生しました\n");
		exit(EXIT_FAILURE);
	}
	ssize_t escritor = write(fd_dest, buff, sizeof(buff));
	if (escritor == -1){
		perror("ファイルを書き込む際にエラーが発生しました\n");
		exit(EXIT_FAILURE);
	}
	close(fd_ori);
	close(fd_dest);
}
