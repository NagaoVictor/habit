#include <stdio.h>

typedef struct {
  int fd;
  int status;
} Device;

// Struct method
Device init_device(){
  Device d;
  d.fd = 3;
  d.status = 1;
  return d;
}

int main(){
  Device dev = init_device();
  printf("fd=%d status%d\n", dev.fd, dev.status);
  return 0;
}
