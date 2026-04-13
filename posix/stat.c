#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

struct stat st;


int main(){
    const char*file="stat.bin";
    const int SIZE=30; //30 Bytes

    int fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0666);
    if (fd == -1 ){
        perror("Open failed\n");
        exit(EXIT_FAILURE);
    }
    if (ftruncate(fd, 100) == -1){
        perror("trunc failed\n");
        exit(EXIT_FAILURE);
    }
    fstat(fd, &st);
    printf("Real size: %ld bytes\n", st.st_size);
    printf("St Mode: %ld \n", st.st_mode);
    printf("Real size: %ld bytes\n", st.st_size);
    printf("Real size: %ld bytes\n", st.st_size);
    printf("Real size: %ld bytes\n", st.st_size);
    printf("Real size: %ld bytes\n", st.st_size);

}