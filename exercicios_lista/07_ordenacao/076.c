#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int particao(int esq, int dir, int vetor[]) {
    int idx = esq + (rand() % (dir - esq));

    int temp = vetor[idx];
    vetor[idx] = vetor[dir];
    vetor[dir] = temp;

    int pivo = vetor[dir];
    int j = esq - 1;

    for (int i = esq; i < dir; i++) {
        if (vetor[i] <= pivo) {
            j++;

            temp = vetor[j];
            vetor[j] = vetor[i];
            vetor[i] = temp;
        }
    }

    temp = vetor[j + 1];
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
    srand(time(NULL));

    int n;
    printf("Insira a quantidade de jogadores: ");
    scanf("%i", &n);

    int pontuacoes[n];
    for (int i = 0; i < n; i++) {
        printf("Insira a pontuação do jogador %i: ", i + 1);
        scanf("%i", &pontuacoes[i]);
    }

    quick_sort(0, n - 1, pontuacoes);

    printf("Pontuações: ");
    for (int i = 0; i < n; i++) {
        printf("%i ", pontuacoes[i]);
    }
    printf("\n");

    return 0;
}