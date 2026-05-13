#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int main(){
  pid_t pid = fork();
  
  if (pid == 0){
  while (1)
    sleep(1);
  }

  sleep(2);
  kill(pid, SIGSTOP);

  int status;
  waitpid(pid, &status, WUNTRACED);

  if (WIFSTOPPED(status)){
    printf("Signal stopped by son %d\n", WSTOPSIG(status));
  }
  kill(pid, SIGKILL);
  waitpid(pid, NULL, 0);
}
