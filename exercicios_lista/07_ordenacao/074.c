#include <stdio.h>

void particao(int n, int vetor[]) {
    int pivo = vetor[n - 1];
    int j = -1;

    for (int i = 0; i < n - 1; i++) {
        if (vetor[i] < pivo) {
            j++;

            int temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
        }
    }

    int temp = vetor[j + 1];
    vetor[j + 1] = vetor[n - 1];
    vetor[n - 1] = temp;
}

int main() {
    int n;
    printf("Insira a quantidade de Mechas: ");
    scanf("%i", &n);

    int vidas_mechas[n];
    for (int i = 0; i < n; i++) {
        printf("Insira a vida do Mecha %i: ", i + 1);
        scanf("%i", &vidas_mechas[i]);
    }

    particao(n, vidas_mechas);

    printf("Mechas particionados: ");
    for (int i = 0; i < n; i++) {
        printf("%i ", vidas_mechas[i]);
    }
    printf("\n");

    return 0;
}