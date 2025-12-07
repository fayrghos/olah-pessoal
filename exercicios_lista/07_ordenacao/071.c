#include <stdio.h>

typedef struct {
    int id;
    int nivel_ameaca;
} NaveInimiga;

void intercala(int esq, int meio, int dir, NaveInimiga vetor[]) {
    int n_esq = (meio - esq) + 1;
    NaveInimiga vetor_esq[n_esq];

    int n_dir = (dir - meio);
    NaveInimiga vetor_dir[n_dir];

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
        if (vetor_esq[i].nivel_ameaca < vetor_dir[j].nivel_ameaca) {
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

void merge_sort(int ini, int fim, NaveInimiga vetor[]) {
    if (ini < fim) {
        int meio = (ini + fim) / 2;

        merge_sort(ini, meio, vetor);
        merge_sort(meio + 1, fim, vetor);

        intercala(ini, meio, fim, vetor);
    }
}

int main() {
    int n;
    printf("Insira a quantidade de naves inimigas: ");
    scanf("%i", &n);

    NaveInimiga naves[n];
    for (int i = 0; i < n; i++) {
        printf("[Nave %i] Insira o ID: ", i + 1);
        scanf("%i", &naves[i].id);

        printf("[Nave %i] Insira o nível de ameaça: ", i + 1);
        scanf("%i", &naves[i].nivel_ameaca);
    }

    merge_sort(0, n - 1, naves);

    printf("Prioridade: ");
    for (int i = 0; i < n; i++) {
        printf("%i ", naves[i].id);
    }
    printf("\n");

    return 0;
}