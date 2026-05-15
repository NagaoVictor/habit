#include <fcntl.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdlib.h>

// Sending int data to devices
#define SET_BRIGHTNESS _IOW('L', 1, int)

int main(){
  int fd = open("/dev/myled", O_RDWR); // My device
  if(fd == -1){
    perror("Open");
    exit(1);
  }
  
  int brightness = 75;
  if (ioctl(fd, SET_BRIGHTNESS, &brightness) == -1)
    perror("ioctl");
  
   close(fd);
   return 0;

}
