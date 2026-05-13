#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(){
  int fd[2];
  pipe(fd);
  
  write(fd[1], "Hello Pipe", 11);
  
  char buff[100] = {0};
  read(fd[0], buff, sizeof(buff));

  printf("Received: %s\n", buff);
  return 0;
}
