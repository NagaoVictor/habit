#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void){
  pid_t pid = fork();
  
  if (pid==0){
    printf("Son process execution\n");
  } else {
    wait(NULL);
    printf("Father process after son process\n");
  }
}
