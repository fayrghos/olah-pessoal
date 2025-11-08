#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    int eliminacoes;
} Jogador;

int main() {
    int n;
    printf("Insira a quantidade de jogadores: ");
    scanf("%i", &n);

    Jogador *jogadores = malloc(sizeof(Jogador) * n);

    for (int i = 0; i < n; i++) {
        printf("[Jogador %i] Insira o nome: ", i + 1);
        scanf(" %s", jogadores[i].nome);

        printf("[Jogador %i] Insira as eliminações: ", i + 1);
        scanf("%i", &jogadores[i].eliminacoes);
    }

    for (int i = 0; i < n; i++) {
        int i_maior = i;

        for (int j = i; j < n; j++) {
            if (jogadores[j].eliminacoes > jogadores[i_maior].eliminacoes) {
                i_maior = j;
            }
        }

        Jogador temp = jogadores[i];
        jogadores[i] = jogadores[i_maior];
        jogadores[i_maior] = temp;
    }

    printf("\n");
    for (int i = 0; i < n; i++) {
        printf(" - Jogador: %s, Eliminações: %i\n", jogadores[i].nome,
               jogadores[i].eliminacoes);
    }

    free(jogadores);
    return 0;
}