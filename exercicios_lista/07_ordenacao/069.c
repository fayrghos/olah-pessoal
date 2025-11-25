#include <stdio.h>

int main() {
    int n;
    printf("Insira a quantidade de inimigos no portal Alfa: ");
    scanf("%i", &n);

    int alfas[n];
    for (int i = 0; i < n; i++) {
        printf("  [Alfa] Insira o nível do inimigo %i: ", i + 1);
        scanf("%i", &alfas[i]);
    }

    int m;
    printf("Insira a quantidade de inimigos no portal Beta: ");
    scanf("%i", &m);

    int betas[m];
    for (int i = 0; i < m; i++) {
        printf("  [Beta] Insira o nível do inimigo %i: ", i + 1);
        scanf("%i", &betas[i]);
    }

    int juncao[n + m];
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < n && j < m) {
        if (alfas[i] < betas[j]) {
            juncao[k] = alfas[i];
            i++;
        }

        else {
            juncao[k] = betas[j];
            j++;
        }

        k++;
    }

    while (i < n) {
        juncao[k] = alfas[i];
        i++;
        k++;
    }

    while (j < m) {
        juncao[k] = betas[j];
        j++;
        k++;
    }

    printf("Ordem: ");
    for (int a = 0; a < n + m; a++) {
        printf("%i ", juncao[a]);
    }
    printf("\n");

    return 0;
}