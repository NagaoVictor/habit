#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
  int fd = open("error.log", O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (fd == -1){
    perror("open");
    return -1;
  }
  
  dup2(fd, STDERR_FILENO);
  close(fd);
  
  fprintf(stderr, "This error was write on errors.log\n");
  return 0;
}
