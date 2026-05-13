#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){
  int fd[2];
  pipe(fd);

  pid_t p1 = fork();
  if (p1 == 0){
    close(fd[0]);
    dup2(fd[1], STDOUT_FILENO);
    close(fd[1]);
  
    execlp("ls", "ls", NULL);
    perror("execlp ls");
    _exit(1);
  }
  
  pid_t p2 = fork();
  if (p2 == 0){
    close(fd[1]);
    dup2(fd[0], STDIN_FILENO);
    close(fd[0]);

    execlp("wc", "wc", "-l", NULL);
    perror("execlp wc");
    _exit(1);
  }

  close(fd[0]);
  close(fd[1]);

  waitpid(p1, NULL, 0);
  waitpid(p2, NULL, 0);

  return 0;
}
