#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int main(){
  for (int i=0; i<3; i++){
    pid_t pid = fork();
    
    if (pid==0){
      printf("Son %d PID=%d\n", i, getpid());
      return 0;
    }
  }
  for (int i=0; i<3; i++); wait(NULL);
}
