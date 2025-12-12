#include <stdio.h>

int particao(int esq, int dir, int vetor[]) {
    int pivo = vetor[dir];
    int j = esq - 1;

    for (int i = esq; i < dir; i++) {
        if (vetor[i] <= pivo) {
            j++;

            int temp = vetor[j];
            vetor[j] = vetor[i];
            vetor[i] = temp;
        }
    }

    int temp = vetor[j + 1];
    vetor[j + 1] = vetor[dir];
    vetor[dir] = temp;

    return j + 1;
}

void quick_sort(int ini, int fim, int vetor[]) {
    if (ini < fim) {
        int pivo = particao(ini, fim, vetor);
        quick_sort(ini, pivo - 1, vetor);
        quick_sort(pivo + 1, fim, vetor);
    }
}

int main() {
    int n;
    printf("Insira a quantidade de jogadores: ");
    scanf("%i", &n);

    int mmrs[n];

    for (int i = 0; i < n; i++) {
        printf("Insira o MMR do jogador %i: ", i + 1);
        scanf("%i", &mmrs[i]);
    }

    quick_sort(0, n - 1, mmrs);

    printf("Ordem dos MMRs: ");
    for (int i = 0; i < n; i++) {
        printf("%i ", mmrs[i]);
    }
    printf("\n");

    return 0;
}