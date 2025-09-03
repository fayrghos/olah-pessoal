#include <stdio.h>

int main() {
    int moedas_coletadas[] = {10, 50, 20, 5, 100};
    int pontuacao_total = 0;
    int *ptr_moeda = moedas_coletadas;

    for (int i = 0; i < 5; i++) {
        pontuacao_total += *ptr_moeda;
        ptr_moeda++;
    }

    printf("Pontuação total do nível: %i\n", pontuacao_total);

    return 0;
}