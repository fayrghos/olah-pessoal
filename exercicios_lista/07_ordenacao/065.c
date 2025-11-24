#include <stdio.h>

typedef struct {
    char nome[50];
    int pontuacao;
} Jogador;

int main() {
    int n;
    printf("Insira a quantidade de jogadores: ");
    scanf("%i", &n);

    Jogador jogadores[n];

    for (int i = 0; i < n; i++) {
        printf("  [Jogador %i] Insira o nome: ", i + 1);
        scanf(" %s", jogadores[i].nome);

        printf("  [Jogador %i] Insira a pontuacao: ", i + 1);
        scanf("%i", &jogadores[i].pontuacao);
    }

    for (int i = 0; i < n; i++) {
        Jogador x = jogadores[i];

        int j;
        for (j = i - 1; j >= 0 && x.pontuacao > jogadores[j].pontuacao; j--) {
            jogadores[j + 1] = jogadores[j];
        }

        jogadores[j + 1] = x;
    }

    printf("Ordem: ");
    for (int i = 0; i < n; i++) {
        printf("%i ", jogadores[i].pontuacao);
    }
    printf("\n");

    return 0;
}