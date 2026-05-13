#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
  int fd = open("everthing.log", O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (fd == -1){
    perror("open");
    return -1;
  }

  dup2(fd, STDOUT_FILENO);
  dup2(STDOUT_FILENO, STDERR_FILENO);
  close(fd);

  printf("normally message\n");
   
  fprintf(stderr, "Message error\n");
  
  return 0;


}
