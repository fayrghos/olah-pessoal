#include <stdio.h>

int main() {
    int n;
    printf("Insira a quantidade de jogadores: ");
    scanf("%i", &n);

    int pontuacoes[n];

    for (int i = 0; i < n; i++) {
        printf("Insira a pontuação do jogador %i: ", i + 1);
        scanf("%i", &pontuacoes[i]);
    }

    for (int i = 0; i < n; i++) {
        int i_menor = i;

        for (int j = i; j < n; j++) {
            if (pontuacoes[j] < pontuacoes[i_menor]) {
                i_menor = j;
            }
        }

        int temp = pontuacoes[i];
        pontuacoes[i] = pontuacoes[i_menor];
        pontuacoes[i_menor] = temp;
    }

    printf("\n");
    printf("Pontuações: ");
    for (int i = 0; i < n; i++) {
        printf("%i ", pontuacoes[i]);
    }
    printf("\n");

    return 0;
}