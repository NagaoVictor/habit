#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(){
  pid_t pid = fork();
  FILE * p;
  p  = fopen("son.txt", "w");
  if (pid == 0){
    fprintf(p, "Hello Brother\n");
  } else {
    wait(NULL);
    fprintf(stdout, "See the son.txt file\n");
   }
  return 0;
}
