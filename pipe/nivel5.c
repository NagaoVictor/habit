#include <unistd.h>
#include <sys/wait.h>

int main(){
  int fd[2];
  pipe(fd);
    
  if (fork() == 0){
    close(fd[0]);
    dup2(fd[1], STDOUT_FILENO);
    close(fd[1]);
    execlp("ls","ls", NULL);
    _exit(1);
  }
  
  if (fork() == 0){
    close(fd[1]);
    dup2(fd[0], STDIN_FILENO);
    close(fd[0]);
    execlp("wc", "wc", "-l", NULL);
    _exit(1);
  }
  
  close(fd[0]);
  close(fd[1]);

  wait(NULL);
  wait(NULL);
  return 0;


}
