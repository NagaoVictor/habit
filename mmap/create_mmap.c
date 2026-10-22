#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>

int main() {
    size_t tamanho = 4096; // 1 página de memória padrão do sistema (4 KB)

    // 1. Mapeando a memória diretamente com o kernel
    void *ptr = mmap(
        NULL,                        // Endereço inicial (NULL = o kernel escolhe)
        tamanho,                     // Tamanho do bloco em bytes
        PROT_READ | PROT_WRITE,      // Permissões: leitura e escrita
        MAP_PRIVATE | MAP_ANONYMOUS, // Privado para o processo e sem arquivo físico
        -1,                          // Sem descritor de arquivo (pois é anônimo)
        0                            // Offset zero
    );

    // Verificação de erro crítica
    if (ptr == MAP_FAILED) {
        perror("Erro no mmap");
        return 1;
    }

    printf("Memória mapeada com sucesso no endereço: %p\n", ptr);

    // 2. Usando a memória como se fosse um vetor de inteiros
    int *numeros = (int *)ptr;
    numeros[0] = 100;
    numeros[1] = 200;
    numeros[2] = 300;

    printf("Valores na memória mapeada: %d, %d, %d\n", numeros[0], numeros[1], numeros[2]);

    // 3. Desfazendo o mapeamento (equivalente ao 'free' para o mmap)
    if (munmap(ptr, tamanho) == -1) {
        perror("Erro no munmap");
        return 1;
    }

    printf("Memória liberada (munmap) com sucesso.\n");
    return 0;
}