#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

pid_t child_pid;

void alarm_handler(int sig){
  kill(child_pid, SIGKILL);
}

int main(){
  signal(SIGALRM, alarm_handler);
  child_pid = fork();
  
  if(child_pid == 0){
    while(1){
      printf("Executing...\n");
      sleep(1);
    }
  }

  alarm(5);
  waitpid(child_pid, NULL, 0);
}
