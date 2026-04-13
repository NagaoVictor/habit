#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>


int main(){
    const char * file = "file.bin";
    const int SIZE = 256;

    char*addr;

    int fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0666);
    if (fd==-1){
        perror("open()\n");
        exit(EXIT_FAILURE);
    }   
    if (ftruncate(fd, SIZE)==-1){
        perror("ftruncate()\n");
        exit(EXIT_FAILURE);
    }

    addr = mmap(NULL, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (addr==MAP_FAILED){
        perror("mmap\n");
        exit(EXIT_FAILURE);
    }

    printf("%d\n",addr);

    char message[] = "Flags insert";
    int message_size = sizeof(message)/sizeof(message[0]);
    for (int i=0; i<message_size;i++){
        addr[i] = message[i];
    }
    printf("%s\n", addr);


    munmap(addr,SIZE); 
    close(fd);



}