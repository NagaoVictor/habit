#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(void){
  int fd[2];
  pipe(fd);

  if (fork()==0){
    close(fd[1]);
    char buff[100];
    read(fd[0], buff, sizeof(buff));
    printf("Son received: %s\n", buff);
  } else {
    close(fd[0]);
    write(1, "Hello\n", 6);
  }
}
