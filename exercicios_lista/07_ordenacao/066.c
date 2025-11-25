#include <stdio.h>

int main() {
    int n;
    printf("Insira a quantidade de jogadores: ");
    scanf("%i", &n);

    int jogadores[n];

    for (int i = 0; i < n; i++) {
        printf(" Insira a pontuação do jogador %i: ", i + 1);
        scanf("%i", &jogadores[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (jogadores[j] < jogadores[j + 1]) {
                int temp = jogadores[j];
                jogadores[j] = jogadores[j + 1];
                jogadores[j + 1] = temp;
            }
        }
    }

    printf("Ordem: ");
    for (int i = 0; i < n; i++) {
        printf("%i ", jogadores[i]);
    }
    printf("\n");
    return 0;
}