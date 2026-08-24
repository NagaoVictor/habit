#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(){
  int fd = open("data.txt", O_WRONLY | O_CREAT, 0666);
  if (fd < 0){
    perror("open");
    exit(1);
  }
  ssize_t w = write(fd, "Hello World", 15);
  printf("---Hello world---");




}
