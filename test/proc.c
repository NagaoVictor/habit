#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
  pid_t p = fork();
  if (p==0){
    printf("Son process\n");
  } else {
    wait(NULL);  
    printf("Father process\n");
    //wait(NULL);
  }

}
