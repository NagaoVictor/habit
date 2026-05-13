#include <stdio.h>
#include <unistd.h>

int main(){
  int fd[2];
  pipe(fd);
  
  pid_t pid = fork();

  if (pid == 0){
    close(fd[0]);
    dup2(fd[1], STDOUT_FILENO);
    close(fd[1]);
    
    printf("Text sent from printf()\n");
    return 0;
  }
  close(fd[1]);
  
  char buff[100] = {0};
  read(fd[0], buff, sizeof(buff));
  
  printf("Father read: %s", buff);
  return 0;

}
