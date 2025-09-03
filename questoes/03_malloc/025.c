#include <stdio.h>
#include <stdlib.h>

int main() {
    int quant_inimigos;

    printf("Insira a quantidade de inimigos: ");
    scanf("%i", &quant_inimigos);

    int *status_inimigos = calloc(quant_inimigos, sizeof(int));

    for (int i = 0; i < quant_inimigos; i++) {
        printf("Inimigo %i: Inativo (%i)\n", i + 1, *(status_inimigos + i));
    }

    for (int i = 0; i < quant_inimigos; i++) {
        *(status_inimigos + i) = 1;
    }

    for (int i = 0; i < quant_inimigos; i++) {
        printf("Inimigo %i: Ativo (%i)\n", i + 1, *(status_inimigos + i));
    }

    free(status_inimigos);
    return 0;
}