#include <stdio.h>
#include <stdint.h>

typedef uint32_t REG32;

#define ENABLE_MASK (1u << 0)
#define RESET_MASK (1u << 1)

#define MODE_SHIFT 2
#define MODE_MASK (0x7u << MODE_SHIFT)

#define SPEED_SHIFT 5
#define SPEED_MASK (0x7u << SPEED_SHIFT)

#define IRQ_MASK (1u << 8)
#define BUSY_MASK (1u << 9)
#define ERROR_MASK (1u << 10)

void device_enable(REG32 *reg){
  *reg |= ENABLE_MASK;
}

void device_disable(REG32 *reg){
  *reg &= ~ENABLE_MASK;
}

void device_reset(REG32 *reg){
  *reg |= RESET_MASK;
}

void device_set_mode(REG32 *reg, uint8_t mode){
  mode &= 0x7;

  *reg &= ~MODE_MASK;
  *reg |= (mode << MODE_SHIFT);
}

uint8_t device_get_mode(REG32 reg){
  return (reg & MODE_MASK) >> MODE_SHIFT;
}

void device_set_speed(REG32 *reg, uint8_t speed){
  speed &= 0x7;
  
  *reg &= ~SPEED_MASK;
  *reg |= (speed << SPEED_SHIFT);
}

uint8_t device_get_speed(REG32 reg){
  return (reg & SPEED_MASK) >> SPEED_SHIFT;
}

void irq_set(REG32 *reg){
  *reg |= IRQ_MASK;
}

void irq_clear(REG32 *reg){
  *reg &= ~IRQ_MASK;
}

void busy_set(REG32 *reg){
  *reg &= ~BUSY_MASK;
}

void error_set(REG32 *reg){
  *reg |= ERROR_MASK;
}

void error_clear(REG32 *reg){
  *reg &= ~ERROR_MASK;
}

void print_binary(REG32 reg){
  for (int i = 31; i>=0; i--){
    printf("%d", (reg >> i) & 1);
    
    if (i % 4 == 0){
      printf(" ");
    }
  }
  printf("\n");
  
}

int main(){
  REG32 control = 0;
  
  device_enable(&control);
  
  device_set_mode(&control, 5);

  device_set_speed(&control, 3);

  irq_set(&control);
  
  busy_set(&control);

  print_binary(control);

  printf("MODE  = %u\n", device_get_mode(control));
  printf("SPEED = %u\n", device_get_speed(control));

  return 0;
}


