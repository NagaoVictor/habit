#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

// Pipe non-blocking

int main(){
  int fd[2];
  pipe(fd);
  
  int flags = fcntl(fd[0], F_GETFL);
  fcntl(fd[0], F_SETFL, flags | O_NONBLOCK);
  
  char buff[100];
  ssize_t n = read(fd[0], buff, sizeof(buff));

  if (n = -1 && errno == EAGAIN){
    printf("No data available\n");
  }
  return 0;


}
