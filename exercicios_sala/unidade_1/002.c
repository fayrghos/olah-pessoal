#include <stdio.h>
#include <stdlib.h>

int main() {
    int *numeros = malloc(sizeof(int) * 5);
    int pares = 0;

    for (int i = 0; i < 5; i++) {
        printf("Insira um número: ");
        scanf("%i", numeros + i);

        if (*(numeros + i) % 2 == 0) {
            pares++;
        }
    }

    printf("Quantidade de pares digitados: %i\n", pares);
    return 0;
}