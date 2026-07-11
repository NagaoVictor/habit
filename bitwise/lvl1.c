#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

int main(){
  uint8_t x = 0b00001000;

  // test bit 3
  if (x & (1 << 3))
  {
    printf("Connected\n");
  }


}
