#include <stdio.h>
#include <stdlib.h>

int main() {
    int quant;

    printf("Insira a quantidade de valores: ");
    scanf("%i", &quant);

    int *valores = malloc(sizeof(int) * quant);
    int posicao, menor;

    for (int i = 0; i < quant; i++) {
        printf("Insira o número %i: ", i + 1);
        scanf("%i", valores + i);

        if (i == 0) {
            menor = *(valores + i);
            posicao = 0;
        }

        if (*(valores + i) < menor) {
            menor = *(valores + i);
            posicao = i;
        }
    }

    printf("Menor valor: %i\n", menor);
    printf("Posicao: %i\n", posicao);
    return 0;
}