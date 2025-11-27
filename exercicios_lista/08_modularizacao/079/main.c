#include "heroi/heroi.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Insira a quantidade de heróis: ");
    scanf("%i", &n);

    Heroi *herois = alocar_herois(n);
    ler_herois(herois, n);
    imprimir_herois(herois, n);

    free(herois);
    return 0;
}