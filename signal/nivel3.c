#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int main(){
  pid_t pid = fork();
  
  if (pid == 0){
    int i = 0;
    while(1){
      printf("Worker: %d\n", i++);
      sleep(1);
    }
  }
  
  sleep(3);
  kill(pid, SIGSTOP);
  printf("Son paused\n");
  
  sleep(3);
  kill(pid, SIGCONT);
  printf("Son resumed\n");

  sleep(3);
  kill(pid, SIGTERM);
  waitpid(pid, NULL, 0);

  return 0;
}
