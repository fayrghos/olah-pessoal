#include <stdio.h>

int main() {
    int placar[6] = {120, 125, 130, 142, 150};
    int novo_tempo;

    printf("Insira o novo tempo: ");
    scanf("%i", &novo_tempo);

    for (int i = 4; i >= -1; i--) {
        if (novo_tempo < placar[i]) {
            placar[i + 1] = placar[i];
        }

        else {
            placar[i + 1] = novo_tempo;
            break;
        }
    }

    printf("Novo placar: ");
    for (int i = 0; i < 5; i++) {
        printf("%i ", placar[i]);
    }
    printf("\n");

    return 0;
}