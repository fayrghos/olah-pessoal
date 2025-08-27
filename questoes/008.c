#include <stdio.h>

int main() {
    int fase[] = {0, 1, 0, 0, 1, 1, 0, 1, 0, 0};
    int *ptr_jogador = fase;
    int moedas_coletadas = 0;

    for (int i = 0; i < 10; i++) {
        if (*(ptr_jogador + i) == 1) {
            moedas_coletadas++;
        }
    }

    printf("O jogador coletou um total de %i moedas!\n", moedas_coletadas);

    return 0;
}