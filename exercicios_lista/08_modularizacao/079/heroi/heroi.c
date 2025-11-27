#include "heroi.h"
#include <stdio.h>
#include <stdlib.h>

struct heroi {
    char nome[50];
    int hp;
    int ataque;
};

Heroi *alocar_herois(int quant) {
    // comentário para evitar o formatador automático, ignore
    return malloc(sizeof(Heroi) * quant);
}

void ler_herois(Heroi *herois, int quant_herois) {
    for (int i = 0; i < quant_herois; i++) {
        printf("  [Heroi %i] Insira o nome: ", i + 1);
        scanf(" %s", herois[i].nome);

        printf("  [Heroi %i] Insira o HP: ", i + 1);
        scanf("%i", &herois[i].hp);

        printf("  [Heroi %i] Insira o ataque: ", i + 1);
        scanf("%i", &herois[i].ataque);
    }
}

void imprimir_herois(Heroi *herois, int quant_herois) {
    for (int i = 0; i < quant_herois; i++) {
        printf("[Herói %i] Nome: %s, HP: %i, Ataque: %i\n", i + 1,
               herois[i].nome, herois[i].hp, herois[i].ataque);
    }
}