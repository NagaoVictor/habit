#include <stdio.h>
#include <stdint.h>


int main(){
  uint8_t REG = 0;
  
  REG |= (1 << 0);
  
  REG |= (1 << 1);

  REG &= ~(0b1111 << 4);
  REG |= (5 << 4);
  
  printf("REG = %d\n", REG);
  
  return 0;

}
