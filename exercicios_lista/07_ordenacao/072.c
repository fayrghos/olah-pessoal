#include <stdio.h>

typedef struct {
    int posicao;
    char nome[50];
} Piloto;

void intercala(int esq, int meio, int dir, Piloto vetor[]) {
    int n_esq = (meio - esq) + 1;
    Piloto vetor_esq[n_esq];

    int n_dir = (dir - meio);
    Piloto vetor_dir[n_dir];

    int k = esq;

    for (int i = 0; i < n_esq; i++) {
        vetor_esq[i] = vetor[esq + i];
    }
    for (int i = 0; i < n_dir; i++) {
        vetor_dir[i] = vetor[meio + i + 1];
    }

    int i = 0;
    int j = 0;

    while (i < n_esq && j < n_dir) {
        if (vetor_esq[i].posicao < vetor_dir[j].posicao) {
            vetor[k] = vetor_esq[i];
            i++;
        }

        else {
            vetor[k] = vetor_dir[j];
            j++;
        }

        k++;
    }

    while (i < n_esq) {
        vetor[k] = vetor_esq[i];
        i++;
        k++;
    }

    while (j < n_dir) {
        vetor[k] = vetor_dir[j];
        j++;
        k++;
    }
}

void merge_sort(int ini, int fim, Piloto vetor[]) {
    if (ini < fim) {
        int meio = (ini + fim) / 2;

        merge_sort(ini, meio, vetor);
        merge_sort(meio + 1, fim, vetor);

        intercala(ini, meio, fim, vetor);
    }
}

int main() {
    int n;
    printf("Insira a quantidade de pilotos: ");
    scanf("%i", &n);

    Piloto pilotos[n];
    for (int i = 0; i < n; i++) {
        printf("[Piloto %i] Insira o nome: ", i + 1);
        scanf(" %s", pilotos[i].nome);

        printf("[Piloto %i] Insira a posição: ", i + 1);
        scanf("%i", &pilotos[i].posicao);
    }

    merge_sort(0, n - 1, pilotos);

    printf("Final:\n");
    for (int i = 0; i < n; i++) {
        printf("  Posição %i - %s\n", pilotos[i].posicao, pilotos[i].nome);
    }

    return 0;
}