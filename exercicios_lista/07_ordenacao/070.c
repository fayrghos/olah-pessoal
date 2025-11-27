#include <stdio.h>

int divisao(int ini, int fim, int vetor[]) {
    if (ini == fim) {
        return vetor[ini];
    }

    if (ini < fim) {
        int meio = (ini + fim) / 2;

        int esq = divisao(ini, meio, vetor);
        int dir = divisao(meio + 1, fim, vetor);

        return esq > dir ? esq : dir;
    }

    return vetor[ini];
}

int main() {
    int n;
    printf("Insira a quantidade de fragmentos: ");
    scanf("%i", &n);

    int fragmentos[n];

    for (int i = 0; i < n; i++) {
        printf("  Insira o poder do fragmento %i: ", i + 1);
        scanf("%i", &fragmentos[i]);
    }

    printf("Mais poderoso: %i\n", divisao(0, n - 1, fragmentos));
    return 0;
}