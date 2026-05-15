#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

// Job control simulator

int main(){
  pid_t pid = fork();
  
  if (pid==0){
    execlp("yes", "yes", NULL);
    _exit(1);
  }
  
  sleep(2);
  kill(pid, SIGSTOP);
  printf("Job stopped\n");

  sleep(2);
  kill(pid, SIGCONT);
  printf("Job resumed\n");

  sleep(2);
  kill(pid, SIGTERM);
  waitpid(pid, NULL, 0);
}
