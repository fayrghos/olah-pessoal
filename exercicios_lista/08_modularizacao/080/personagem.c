#include "personagem.h"
#include <stdio.h>
#include <stdlib.h>

struct personagem {
    char nome[50];
    char classe[50];
    int nivel;
    int hp;
};

Personagem *cria_party(int num_membros) {
    return malloc(sizeof(Personagem) * num_membros);
}

void registra_membros(Personagem *party, int num_membros) {
    for (int i = 0; i < num_membros; i++) {
        printf("  [Membro %i] Insira o nome: ", i + 1);
        scanf(" %s", party[i].nome);

        printf("  [Membro %i] Insira a classe: ", i + 1);
        scanf(" %s", party[i].classe);

        printf("  [Membro %i] Insira o nível: ", i + 1);
        scanf("%i", &party[i].nivel);

        printf("  [Membro %i] Insira o HP: ", i + 1);
        scanf("%i", &party[i].hp);
    }
}

void exibe_relatorio(const Personagem *party, int num_membros) {
    for (int i = 0; i < num_membros; i++) {
        printf("[Membro %i] Nome: %s, Classe: %s, Nível: %i, HP: %i\n", i + 1,
               party[i].nome, party[i].classe, party[i].nivel, party[i].hp);
    }
}

void libera_party(Personagem *party) {
    // comentário para evitar o formatador automático
    free(party);
}