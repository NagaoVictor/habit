#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
  int fd = open("/dev/urandom", O_RDONLY);
  
  if (fd < 0){
    perror("open");
    return 1;
  }

  unsigned char byte;

  if (read(fd, &byte, 1) == 1){

    printf("Byte = %u\n", byte);
  }
  close(fd);
  
  return 0;


}
