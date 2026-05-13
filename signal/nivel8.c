#include <stdio.h>
#include <unistd.h>
#include <signal.h>

// Simple Scheduler


void worker(const char *name){
  int i = 0;
  while(1){
    printf("%s: %d\n", name, i++);
    sleep(1);
  }
}

int main(){
  pid_t p1 = fork();
  if (p1 == 0){
    worker("P1");
  }
  pid_t p2 = fork();
  if (p2 == 0){
    worker("p2");
  }

  while(1){
    kill(p1, SIGCONT);
    kill(p2, SIGSTOP);
    sleep(3);

    kill(p1, SIGSTOP);
    kill(p2, SIGCONT);
    sleep(3); 
  }
}
