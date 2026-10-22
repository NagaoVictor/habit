#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>

int main() {
    size_t tamanho = 4096; // 4 KB (1 página)

    // Alocação Privada e Anônima
    char *ptr = mmap(
        NULL, 
        tamanho, 
        PROT_READ | PROT_WRITE, 
        MAP_PRIVATE | MAP_ANONYMOUS, 
        -1, 
        0
    );

    if (ptr == MAP_FAILED) {
        perror("mmap falhou");
        return 1;
    }

    printf("[PID %d] Memoria mapeada no endereco virtual: %p\n", getpid(), (void *)ptr);

    // Escrevendo dados na memória mapeada
    strcpy(ptr, "Hello, Low-Level mmap!");
    printf("Dado escrito na memoria: %s\n", ptr);

    printf("\nPressione ENTER para liberar a memoria e encerrar...\n");
    getchar();

    // Desfazendo o mapeamento
    if (munmap(ptr, tamanho) == -1) {
        perror("munmap falhou");
        return 1;
    }

    printf("Memoria liberada com sucesso.\n");
    return 0;
}