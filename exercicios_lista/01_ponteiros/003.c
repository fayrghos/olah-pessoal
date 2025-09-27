#include <stdio.h>

int main() {
    float coordenada_x;
    float *ptr_x = &coordenada_x;

    printf("Insira a coordenada X: ");
    scanf("%f", ptr_x);

    printf("Posicao do portal no eixo X: %f\n", *ptr_x);
    printf("Endereco do portal para teletransporte: %p\n", ptr_x);

    return 0;
}