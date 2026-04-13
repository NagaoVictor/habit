#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stddef.h>

struct stat st;

typedef struct __attribute__((packed)){
        int id; // 4 Byter
        double value; // 8 Bytes
        char name[32]; // 32 obvious Bytes
} Register;

int main(){
    const int struct_size = sizeof(Register); 
    //printf("%zu\n", sizeof(Register));

    int fd = open("data.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
    if (fd==-1){
        perror("open() failed");
        exit(EXIT_FAILURE);
    }
    //printf("%d\n", fd);

    if (ftruncate(fd, struct_size)==-1){
        perror("ftruncate() failed");
        exit(EXIT_FAILURE);
    }

    Register * addr = mmap(NULL, struct_size, PROT_READ | PROT_WRITE, MAP_SHARED,fd, 0);
    if (addr==MAP_FAILED){
        perror("mmap failed");
        exit(EXIT_FAILURE);
    }
    // malloc -> HEAP;  mmap -> kernel process 
    addr->id = 20;
    addr->value = 250.30;
    strcpy(addr->name, "Victor\n");


    munmap(addr,struct_size); 
    close(fd);
    return 0;



}