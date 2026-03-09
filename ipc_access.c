#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>



int main(int argc, char*argv[]){
	if (argc < 1){
		fprintf(stderr,"引数が足りません\n");
		exit(EXIT_FAILURE);
	}
	
	int fd = open("/dev/i2c-1", O_RDWR);
	if (fd == -1){
		perror("ファイルを開く際にエラーが発生しました\n");
		exit(EXIT_FAILURE);
	}
	
	if (ioctl(fd, I2C_SLAVE, 0x40) < 0) {
		perror("検出せんでした\n");
		exit(EXIT_FAILURE);
	}
	printf("検出された\n");
	close(fd);


}
