#include <stdio.h>

void particao(int n, int v[]) {
    int s[n];
    int pivo = v[n - 1];

    int esq = 0;
    int dir = n - 1;

    for (int i = 0; i < n; i++) {
        if (v[i] <= pivo) {
            s[esq] = v[i];
            esq++;
        }

        else {
            s[dir] = v[i];
            dir--;
        }
    }

    for (int i = 0; i < n; i++) {
        v[i] = s[i];
    }
}

int main() {
    int n;
    printf("Insira a quantidade de naves itens: ");
    scanf("%i", &n);

    int v[n];

    for (int i = 0; i < n; i++) {
        printf("[Item %i] Insira o nível de poder: ", i + 1);
        scanf("%i", &v[i]);
    }

    particao(n, v);

    printf("Níveis particionados: ");
    for (int i = 0; i < n; i++) {
        printf("%i ", v[i]);
    }
    printf("\n");

    return 0;
}