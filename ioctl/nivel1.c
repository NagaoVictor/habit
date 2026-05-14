#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>


int main(){
  int fd = open("/dev/null", O_RDONLY); // OPEN DEVICE
  ioctl(fd ,0); // CONTROL DEVICE
  close(fd); // CLOSE DEVICE
  return 0;
}
