#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>

#define I2C_DEV "/dev/i2c-1"
#define OLED_ADDR 0x3C

int i2c_fd;

// Seleciona o dispositivo I2C ativo
void selecionar_dispositivo(int addr) {
    if (ioctl(i2c_fd, I2C_SLAVE, addr) < 0) {
        perror("Erro ao selecionar dispositivo I2C");
        exit(1);
    }
}

// Envia um comando isolado para o OLED
void oled_command(unsigned char cmd) {
    selecionar_dispositivo(OLED_ADDR);
    unsigned char buffer[2];
    buffer[0] = 0x00; // Co-byte: indica comando
    buffer[1] = cmd;
    write(i2c_fd, buffer, 2);
}

// Inicialização básica do SSD1306 (128x64)
void oled_init() {
    oled_command(0xAE); // Display OFF
    oled_command(0xD5); // Set Display Clock Divide Ratio/Oscillator Frequency
    oled_command(0x80);
    oled_command(0xA8); // Set Multiplex Ratio
    oled_command(0x3F); // 64 linhas
    oled_command(0xD3); // Set Display Offset
    oled_command(0x00);
    oled_command(0x40); // Set Start Line
    oled_command(0x8D); // Charge Pump Setting
    oled_command(0x14); // Enable Charge Pump
    oled_command(0x20); // Memory Addressing Mode
    oled_command(0x00); // Horizontal addressing mode
    oled_command(0xA1); // Set Segment Re-map
    oled_command(0xC8); // Set COM Output Scan Direction
    oled_command(0xDA); // Set COM Pins Hardware Configuration
    oled_command(0x12);
    oled_command(0x81); // Set Contrast Control
    oled_command(0xCF);
    oled_command(0xD9); // Set Pre-charge Period
    oled_command(0xF1);
    oled_command(0xDB); // Set VCOMH Deselect Level
    oled_command(0x40);
    oled_command(0xA4); // Entire Display On (Resume)
    oled_command(0xA6); // Set Normal Display (Not inverted)
    oled_command(0xAF); // Display ON
}

void oled_enviar_dados(unsigned char *dados, int tamanho) {
    selecionar_dispositivo(OLED_ADDR);
    
    // Precisamos alocar um buffer temporário que leve o 0x40 seguido dos dados
    unsigned char *buffer = malloc(tamanho + 1);
    buffer[0] = 0x40; // Co-byte: indica que o que vem a seguir são DADOS de pixels
    for (int i = 0; i < tamanho; i++) {
        buffer[i + 1] = dados[i];
    }
    
    write(i2c_fd, buffer, tamanho + 1);
    free(buffer);
}


int main() {
    // 1. Abre o barramento I2C do Linux
    i2c_fd = open(I2C_DEV, O_RDWR);
    if (i2c_fd < 0) {
        perror("Erro ao abrir /dev/i2c-1");
        return 1;
    }

    printf("Inicializando o OLED SSD1306...\n");
    oled_init();
    printf("OLED inicializado com sucesso!\n");


    // Exemplo simplificado das 5 colunas de pixels que formam a letra 'A'
    unsigned char letra_A[5] = {0x7E, 0x11, 0x11, 0x11, 0x7E};

    close(i2c_fd);
    return 0;
}