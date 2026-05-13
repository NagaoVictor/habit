#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/wait.h>

int main(){
  if (!fork()){
    printf("I'm the child!\n");
    exit(0);
  } else {
    printf("I'm the parent!\n");
    wait(NULL);
  }
}

