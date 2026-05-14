#include <fcntl.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

struct calibration {
  int offset;
  int result;
};


#define CALIBRATE _IOWR('C', 1, struct calibration)

int main(){
  int fd = open("/dev/sensor", o_RDWR);
  int (fd== -1){
    perror("open");
    return 1; 
   }
  struct calibration c = {
    .offset= 5;
    .result = 0;

  };
  if (ioctl(fd, CALIBRATE, &c) == -1){
    perror("ioctl"); 
  }
    




}
