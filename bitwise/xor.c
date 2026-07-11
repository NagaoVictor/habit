#include <stdio.h>
#include <stdint.h>

void print_bits(uint8_t reg, uint8_t size){
  for (int i = size; i>=0; i--){
    printf("%d", (reg >> i) & 1);
  }
  printf("\n");
}

int main(){
  uint8_t reg = 0b00001010;
  reg ^= 0b00000010;

  printf("reg = 1010\n");
  printf("bitmask = 0010\nreturn = ");
  print_bits(reg, 7);

}
