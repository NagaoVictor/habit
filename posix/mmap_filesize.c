#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

struct stat st;

int main(int argc, char*argv[]){
    const char * file = "file.txt";
    int SIZE = 40;
    
    int fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0666);
    if (fd == -1){
        perror("open error\n");
        exit(EXIT_FAILURE);
    }
    if (ftruncate(fd, SIZE)==-1){
        perror("ftruncate() error\n");
        exit(EXIT_FAILURE);
    }

    fstat(fd, &st);
    if (st.st_size < SIZE){
        perror("No memory allocated error\n");
        exit(EXIT_FAILURE);
    }

    char * addr = mmap(NULL, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (addr == MAP_FAILED){
        perror("mmap failed\n");
        exit(EXIT_FAILURE);
    }

    char word[5] = "test";
    for (int i=0; i<5; i++){
        addr[i] = word[i]; 
    }

    printf("%s\n", addr);

    munmap(addr,100); 
    close(fd);
    return 0;

}
