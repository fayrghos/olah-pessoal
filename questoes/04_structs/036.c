#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pos_x;
    int pos_y;
    int valor;
} Moeda;

int main() {
    int quant_moedas;

    printf("Insira a quantidade de moedas: ");
    scanf("%i", &quant_moedas);

    Moeda *moedas = malloc(sizeof(Moeda) * quant_moedas);

    for (int i = 0; i < quant_moedas; i++) {
        printf("Insira a posição X, posição Y e valor da moeda %i: ", i + 1);
        scanf("%i %i %i", &moedas[i].pos_x, &moedas[i].pos_y, &moedas[i].valor);
    }

    int total_pontos = 0;
    for (int i = 0; i < quant_moedas; i++) {
        total_pontos += moedas[i].valor;
    }

    printf("Pontuacao maxima do nivel: %i\n", total_pontos);

    free(moedas);
    return 0;
}