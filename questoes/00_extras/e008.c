#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    printf("Insira o valor de N: ");
    scanf("%i", &n);

    int *linhas = malloc(sizeof(int) * n);

    float total_abaixo = 0;
    float quant_abaixo = 0;

    for (int i = 0; i < n; i++) {
        printf("Linha %i:   ", i + 1);
        for (int j = 0; j < n; j++) {
            scanf("%i", &linhas[i] + j);

            if (i + j > n - 1) {
                total_abaixo += *(&linhas[i] + j);
                quant_abaixo++;
            }
        }
    }

    float media = total_abaixo / quant_abaixo;
    printf("A média dos elementos abaixo da diagonal principal foi: %f\n",
           media);

    return 0;
}