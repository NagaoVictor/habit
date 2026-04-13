#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>
#include <string.h>



int main(){
    char* file = "dados.bin";

    int fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0666);
    if (fd == -1 ){
        perror("Open failed\n");
        exit(EXIT_FAILURE);
    }
    ftruncate(fd, 100); // 100bytes
    printf("%zu Bytes\n", sizeof(fd));


    char * addr = mmap(NULL, 100, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (addr == MAP_FAILED){
        perror("mmap failed\n");
        exit(EXIT_FAILURE);
    }


    strcpy(addr, "HELLO FROM MAP");
    printf("Addr content: %s\n", addr);

    munmap(addr,100); // 100bytes size
    close(fd);
    return 0;


}