#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/wait.h>


int main(){
  fork();
  printf("Hello\n");
  fork();
  
  fork();
}

