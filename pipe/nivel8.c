#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(){
  int fd[2];
  pipe(fd);

  if(fork() == 0){
    close(fd[0]);
    write(fd[1], "Row 1\n", 8);
    write(fd[1], "Row 2\n", 8);
    close(fd[1]);
    _exit(0);
  }
  close(fd[1]);
  
  char buff[128]; 
  ssize_t n;

  while ((n = read(fd[0], buff, sizeof(buff))) > 0){
    write(STDOUT_FILENO, buff, n);
  }
  
  printf("EOF detected\n");
  wait(NULL);
  return 0;

}
