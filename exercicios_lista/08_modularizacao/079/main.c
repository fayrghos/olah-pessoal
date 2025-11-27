#include "heroi/heroi.h"
#include <stdio.h>

int main() {
    int n;
    printf("Insira a quantidade de heróis: ");
    scanf("%i", &n);

    Heroi *herois = alocar_herois(n);
    ler_herois(herois, n);
    imprimir_herois(herois, n);

    return 0;
}