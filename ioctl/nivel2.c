#include <stdio.h>
#include <sys/ioctl.h>

// _IO represent no data availablegoo
// _IOR FROM driver TO USER
// _IOW FROM uset to driver
// _IOWR Bidirecional

#define LED_ON _IO('L', 1)
#define LED_OFF _IO('L', 2)
#define RESET _IO('L', 3)



int main(){
  printf("LED_ON = 0x%08lx\n", (unsigned long)LED_ON);
  printf("LED_OFF = 0x%08lx\n", (unsigned long)LED_OFF);
  printf("RESET = 0x%08lx\n", (unsigned long)RESET);

}
