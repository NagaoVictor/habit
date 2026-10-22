#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 5;
    int *ptr = NULL;

    // 1. Alocando espaço para 5 inteiros no Heap
    ptr = (int *)malloc(n * sizeof(int));
    
    // Sempre verifique se o ponteiro é NULL para evitar falhas de segmentação
    if (ptr == NULL) {
        fprintf(stderr, "Erro: Falha na alocação de memória!\n");
        return 1;
    }

    // 2. Usando a memória alocada normalmente como um vetor
    for (int i = 0; i < n; i++) {
        ptr[i] = (i + 1) * 10;
        printf("Elemento ptr[%d] = %d\n", i, ptr[i]);
    }

    // 3. Liberando a memória alocada
    free(ptr);
    
    // Boa prática: anular o ponteiro após liberar para evitar "dangling pointers"
    ptr = NULL; 

    printf("Memória liberada com sucesso.\n");
    return 0;
}