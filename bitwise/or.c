#include <stdio.h>
#include <stdint.h>

void print_bit(uint8_t reg, uint8_t size){
  for (int i = size; i>=1; i--){
    printf("%d", (reg>>i)&1);
  }
  printf("\n");
}

int main(){
  
  uint8_t reg = 0b00001010;
  printf("Bit reg = 1010\n");
  reg |= 0b00000100;
  printf("reg |= 0100 => ");
  print_bit(reg, 8);


}
