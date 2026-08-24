#include <stdio.h>
#include <stdint.h>

int main(){
  uint8_t reg = 0b00001010;
  if (reg & 0b00000010){
    printf("Bit 1 on\n");
  }
}
