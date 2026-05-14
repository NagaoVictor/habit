#include <fcntl.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdlib.h>

// Receive int data from device
#define GET_TEMPERATURE _IOR('T', 1, int)

int main(){
  int fd = open("/dev/tempsensor", O_RDONLY);
  if (fd == -1){
    perror("open");
    exit(1);
  }
  
  int temp;
  
  if (ioctl(fd, GET_TEMPERATURE, &temp) == -1){
    perror("ioctl");

  } else {
    printf("Temperature: %d degrees\n", temp);
  }
  
  close(fd);
  return 0;


}
