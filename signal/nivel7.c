#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// Watchdogs
// Restart process when the process finished

int main(){
  while(1){
    pid_t pid = fork();

    if (pid == 0){
      printf("Worker starting\n"); 
      sleep(3);
      printf("Worker finishing\n");
      exit(1);
    }
    int status;
    waitpid(pid, &status, 0);
    printf("Worker restarting\n");
  }


}
