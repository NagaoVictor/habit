#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>

#define I2C_BUS "/dev/i2c-1" // Caminho padrão do barramento I2C no Linux
#define TARGET_ADDR 0x68     // Exemplo: Endereço I2C típico de um acelerômetro MPU6050

int main() {
    int file_fd;
    unsigned char reg_to_read = 0x75; // Exemplo: Registrador "WHO_AM_I" de muitos chips
    unsigned char data_buffer = 0;

    // 1. Abre o descritor de arquivo do barramento I2C
    file_fd = open(I2C_BUS, O_RDWR);
    if (file_fd < 0) {
        perror("Erro ao abrir o barramento I2C");
        return 1;
    }

    // 2. O CORAÇÃO DO IOCTL: Configura o endereço do chip escravo no barramento
    // O kernel recebe 'file_fd', aplica o comando I2C_SLAVE e muda o alvo ativo.
    if (ioctl(file_fd, I2C_SLAVE, TARGET_ADDR) < 0) {
        perror("Erro ao definir o endereço do escravo via ioctl");
        close(file_fd);
        return 1;
    }
    printf("[+] ioctl executado com sucesso: Endereço I2C 0x%02X selecionado.\n", TARGET_ADDR);

    // 3. Escreve qual registrador interno queremos consultar (usando a syscall write padrão)
    if (write(file_fd, &reg_to_read, 1) != 1) {
        perror("Erro ao enviar o endereço do registrador");
    } else {
        // 4. Lê o byte de resposta do registrador do chip (usando a syscall read padrão)
        if (read(file_fd, &data_buffer, 1) != 1) {
            perror("Erro ao ler dados do dispositivo");
        } else {
            printf("[+] Sucesso! Resposta do chip (Registrador 0x%02X): 0x%02X\n", reg_to_read, data_buffer);
        }
    }

    // Fecha o descritor de arquivo
    close(file_fd);
    return 0;
}