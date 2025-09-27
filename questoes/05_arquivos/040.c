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
    Jogador *melhor_jogador = &jogadores[0];

    for (int i = 0; i < n; i++) {
        printf("Insira o nome do Jogador %i: ", i + 1);
        scanf(" %[^\n]s", jogadores[i].nome);

        printf("Insira a pontuação do Jogador %i: ", i + 1);
        scanf("%i", &jogadores[i].pontuacao);

        if (jogadores[i].pontuacao > melhor_jogador->pontuacao) {
            melhor_jogador = &jogadores[i];
        }
    }

    FILE *txt = fopen("./highscore.txt", "w");

    fprintf(txt, "Nome: %s, Pontuacao: %i", melhor_jogador->nome,
            melhor_jogador->pontuacao);

    fclose(txt);
    return 0;
}