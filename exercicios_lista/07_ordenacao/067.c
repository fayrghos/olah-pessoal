#include <stdio.h>

int main() {
    int n;
    printf("Insira a quantidade de jogadores: ");
    scanf("%i", &n);

    int pontuacoes[n];

    for (int i = 0; i < n; i++) {
        printf("  Insira a pontuação do jogador %i: ", i + 1);
        scanf("%i", &pontuacoes[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        int trocou = 0;

        for (int j = 0; j < n - i - 1; j++) {
            if (pontuacoes[j] < pontuacoes[j + 1]) {
                int temp = pontuacoes[j];
                pontuacoes[j] = pontuacoes[j + 1];
                pontuacoes[j + 1] = temp;

                trocou = 1;
            }
        }

        if (!trocou) {
            break;
        }
    }

    printf("Ordem: ");
    for (int i = 0; i < n; i++) {
        printf("%i ", pontuacoes[i]);
    }
    printf("\n");
    return 0;
}