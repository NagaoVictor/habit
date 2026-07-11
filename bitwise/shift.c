// Bit shift left
#include <stdio.h>
#include <stdint.h>

void print_bits(uint8_t reg, uint8_t size){
  for (int i = size; i>=0; i--){
    printf("%d", (reg >> i)&1); 
  }
  printf("\n");
}

void shift_right(uint8_t * reg, uint8_t shift){
  *reg>>=shift;
}

void shift_left(uint8_t * reg, uint8_t shift){
  *reg<<=shift;
}

int main(){
  uint8_t reg = 0b00001010;
  print_bits(reg, 7);
  uint8_t left = 3;
  shift_left(&reg, left);
  print_bits(reg, 7);
  uint8_t right = 1;
  shift_right(&reg, right);
  print_bits(reg, 7);

}
