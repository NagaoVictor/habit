#include <stdio.h>
#include <unistd.h>

int main(void){
  pid_t pid = fork();
  if (pid==0){
    printf("Son\n");
  } else {
    printf("Father\n");
  }
}
