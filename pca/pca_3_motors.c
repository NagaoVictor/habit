#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>

#define PCA9685_ADDR  0x40
#define REG_MODE1     0x00
#define REG_PRESCALE  0xFE

static struct termios oldt, newt;

// Ativa modo nao-canonico com timeout de 200ms (VTIME = 2) para detectar quando solta a tecla
static void enable_raw_mode(void) {
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    newt.c_cc[VMIN] = 0;   // Nao bloqueia indefinidamente se nenhuma tecla for apertada
    newt.c_cc[VTIME] = 2;  // Timeout de 0.2 segundos (200 ms)
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}

static void disable_raw_mode(void) {
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}

static int pca_write_reg(int fd, uint8_t reg, uint8_t val) {
    uint8_t buf = { reg, val };
    return (write(fd, buf, 2) == 2) ? 0 : -1;
}

static void pca_set_pwm(int fd, uint8_t canal, uint16_t duty) {
    if (canal > 15) return;
    if (duty > 4095) duty = 4095;

    uint8_t base_reg = 0x06 + (4 * canal);
    pca_write_reg(fd, base_reg,     0x00);
    pca_write_reg(fd, base_reg + 1, 0x00);
    pca_write_reg(fd, base_reg + 2, duty & 0xFF);
    pca_write_reg(fd, base_reg + 3, (duty >> 8) & 0x0F);
}

static void parar_todos(int fd) {
    pca_set_pwm(fd, 0, 0);
    pca_set_pwm(fd, 1, 0);
    pca_set_pwm(fd, 2, 0);
}

int main(void) {
    int fd = open("/dev/i2c-1", O_RDWR);
    if (fd < 0) {
        perror("Erro ao abrir /dev/i2c-1");
        return EXIT_FAILURE;
    }

    if (ioctl(fd, I2C_SLAVE, PCA9685_ADDR) < 0) {
        perror("Erro ao selecionar PCA9685 (0x40)");
        close(fd);
        return EXIT_FAILURE;
    }

    // Inicializa PCA9685 (~50 Hz com Auto-Increment ativo)
    pca_write_reg(fd, REG_MODE1, 0x10);
    pca_write_reg(fd, REG_PRESCALE, 121);
    pca_write_reg(fd, REG_MODE1, 0x20);
    usleep(5000);

    parar_todos(fd);
    enable_raw_mode();

    printf("=== CONTROLE DE 3 MOTORES (PCA9685) ===\n");
    printf("Segure [A] Motor 0 | [S] Motor 1 | [D] Motor 2 | [Q] Sair\n");

    char c;
    int ultimo_ativo = -1;

    while (1) {
        ssize_t n = read(STDIN_FILENO, &c, 1);

        if (n > 0) {
            if (c == 'q' || c == 'Q') break;

            if (c == 'a' || c == 'A') {
                if (ultimo_ativo != 0) {
                    parar_todos(fd);
                    pca_set_pwm(fd, 0, 4095); // Liga Canal 0 (100%)
                    ultimo_ativo = 0;
                }
            } else if (c == 's' || c == 'S') {
                if (ultimo_ativo != 1) {
                    parar_todos(fd);
                    pca_set_pwm(fd, 1, 4095); // Liga Canal 1 (100%)
                    ultimo_ativo = 1;
                }
            } else if (c == 'd' || c == 'D') {
                if (ultimo_ativo != 2) {
                    parar_todos(fd);
                    pca_set_pwm(fd, 2, 4095); // Liga Canal 2 (100%)
                    ultimo_ativo = 2;
                }
            }
        } else {
            // Timeout de 200ms sem tecla pressionada -> soltou o dedo!
            if (ultimo_ativo != -1) {
                parar_todos(fd);
                ultimo_ativo = -1;
            }
        }
    }

    parar_todos(fd);
    disable_raw_mode();
    close(fd);
    printf("\nMotores desligados e terminal restaurado.\n");
    return EXIT_SUCCESS;
}
