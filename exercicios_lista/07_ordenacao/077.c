#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int id;
    int pontuacao;
} Jogador;

int particao(int esq, int dir, Jogador vetor[]) {
    int idx = esq + (rand() % (dir - esq));

    Jogador temp = vetor[idx];
    vetor[idx] = vetor[dir];
    vetor[dir] = temp;

    Jogador pivo = vetor[dir];
    int j = esq - 1;

    for (int i = esq; i < dir; i++) {
        if (vetor[i].pontuacao >= pivo.pontuacao) {
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

void quick_sort(int ini, int fim, Jogador vetor[]) {
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

    Jogador jogadores[n];
    for (int i = 0; i < n; i++) {
        printf("  [Jogador %i] Insira o ID: ", i + 1);
        scanf("%i", &jogadores[i].id);

        printf("  [Jogador %i] Insira a pontuação: ", i + 1);
        scanf("%i", &jogadores[i].pontuacao);
    }

    quick_sort(0, n - 1, jogadores);

    printf("Ordenados:\n");
    for (int i = 0; i < n; i++) {
        printf("  ID %i - Pontuação: %i\n", jogadores[i].id,
               jogadores[i].pontuacao);
    }

    return 0;
}