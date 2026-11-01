#include <stdio.h>

typedef struct {
    float b0, b1, b2; // Coeficientes do numerador (Zeros)
    float a1, a2;     // Coeficientes do denominador (Pólos)
    float w1, w2;     // Estados internos do buffer (Delay elements)
} BiquadFilter;

/**
 * Processa uma única amostra usando a estrutura IIR Biquad
 */
float process_iir(BiquadFilter *filt, float input) {
    // 1. Calcula o novo estado interno (Forma Direta II Transposta)
    float w0 = input - filt->a1 * filt->w1 - filt->a2 * filt->w2;
    
    // 2. Calcula a saída baseada nos coeficientes de avanço
    float output = filt->b0 * w0 + filt->b1 * filt->w1 + filt->b2 * filt->w2;
    
    // 3. Atualiza os estados de atraso
    filt->w2 = filt->w1;
    filt->w1 = w0;

    return output;
}

int main(void) {
    // Exemplo de inicialização de um filtro digital bi-quadrático
    BiquadFilter my_filter = {
        .b0 = 0.0675f, .b1 = 0.1350f, .b2 = 0.0675f,
        .a1 = -1.1430f, .a2 = 0.4128f,
        .w1 = 0.0f, .w2 = 0.0f
    };

    float test_input = 1.0f; // Impulso unitário
    printf("Resposta ao Impulso IIR:\n");
    for (int n = 0; n < 5; n++) {
        float out = process_iir(&my_filter, test_input);
        printf("n[%d] = %.4f\n", n, out);
        test_input = 0.0f; // Degrau vira impulso após n=0
    }

    return 0;
}