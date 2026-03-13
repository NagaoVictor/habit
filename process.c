#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>


// RACE CONDITON SIMULATE

int main(){
	pid_t process = fork();
	char buff[2048];
	
	int fd = open("process_test.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1){
		fprintf(stderr, "Create error\n");
		exit(EXIT_FAILURE);
	}

	ssize_t writer1;
	ssize_t writer2;

	
	if (process == 0){
		writer1 = write(fd,"Son in command", sizeof(buff));
		if (writer1 == -1){
			perror("Write1 writing error occur\n");
			exit(1);
		}
	} else {
		writer2 = write(fd, "Father in command", sizeof(buff));
		if (writer2 == -1){
			perror("Write2 writing error occur\n");
			exit(EXIT_FAILURE);
		}
	}


	ssize_t reader = (fd, buff, sizeof(buff));
	if (reader==-1){
		perror("Read problem\n");
		exit(EXIT_FAILURE);
	}
	printf("%s\n", buff);
	close(fd);

}
