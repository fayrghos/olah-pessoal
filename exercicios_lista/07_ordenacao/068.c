#include <stdio.h>

typedef struct {
    int id;
    int pontuacao;
} Jogador;

int main() {
    int n;
    printf("Insira a quantidade de jogadores: ");
    scanf("%i", &n);

    Jogador jogadores[n];

    for (int i = 0; i < n; i++) {
        printf("  [Jogador %i] Insira o ID: ", i + 1);
        scanf("%i", &jogadores[i].id);

        printf("  [Jogador %i] Insira a pontuação: ", i + 1);
        scanf("%i", &jogadores[i].pontuacao);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (jogadores[j].pontuacao < jogadores[j + 1].pontuacao) {
                Jogador temp = jogadores[j];
                jogadores[j] = jogadores[j + 1];
                jogadores[j + 1] = temp;
            }
        }
    }

    printf("Ordem:\n");
    for (int i = 0; i < n; i++) {
        printf("  [ID %i] Pontos: %i\n", jogadores[i].id,
               jogadores[i].pontuacao);
    }

    return 0;
}