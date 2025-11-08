#include "stdio.h"

typedef struct {
    int id;
    char nome[50];
    int hp;
    int ataque;
} Monstro;

int busca_bin_rec(int desejado, Monstro monstros[], int ini, int fim) {
    if (ini > fim) {
        return -1;
    }

    int meio = (ini + fim) / 2;

    if (monstros[meio].id == desejado) {
        return meio;
    }

    if (monstros[meio].id < desejado) {
        return busca_bin_rec(desejado, monstros, meio + 1, fim);
    }

    return busca_bin_rec(desejado, monstros, ini, meio - 1);
}

int main() {
    int n;

    printf("Insira a quantidade de monstros: ");
    scanf("%i", &n);

    Monstro monstros[n] = {};
    for (int i = 0; i < n; i++) {
        printf("Insira o ID do monstro %i: ", i + 1);
        scanf("%i", &monstros[i].id);

        printf("  Insira seu nome: ");
        scanf(" %s", monstros[i].nome);

        printf("  Insira seu HP: ");
        scanf("%i", &monstros[i].hp);

        printf("  Insira seu ataque: ");
        scanf("%i", &monstros[i].ataque);
    }

    for (;;) {
        int opcao;

        printf("Busque um ID: ");
        scanf("%i", &opcao);

        if (opcao == 0) {
            break;
        }

        int encontrado = busca_bin_rec(opcao, monstros, 0, n);
        if (encontrado < 0) {
            printf("Monstro com ID %i nao encontrado.\n\n", opcao);
            continue;
        }

        printf("Monstro Encontrado: %s (ID: %i) - HP: %i, Ataque: %i.\n\n",
               monstros[encontrado].nome, monstros[encontrado].id,
               monstros[encontrado].hp, monstros[encontrado].ataque);
    }

    return 0;
}