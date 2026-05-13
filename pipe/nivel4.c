#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
  int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
  
  dup2(fd, STDOUT_FILENO);
  close(fd);

  printf("This row is going to file\n");
  return 0;
}

