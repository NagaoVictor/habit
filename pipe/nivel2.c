#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
  int fd[2];
  pipe(fd);
  
  pid_t pid = fork();
  
  if (pid == 0){
    close(fd[1]);
    
    char buff[100] = {0};
    read(fd[0], buff, sizeof(buff));
    printf("Son received: %s\n", buff);
    return 0;
  }
  close(fd[0]);
  write(fd[1], "Father of message", 16);
  close(fd[1]);
  
  wait(NULL);
  return 0;
}
