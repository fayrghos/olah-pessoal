#include <stdio.h>

int main() {
    int n;
    printf("Insira a quantidade de fragmentos: ");
    scanf("%i", &n);

    int fragmentos[n];

    for (int i = 0; i < n; i++) {
        printf("  Insira o poder do fragmento %i: ", i + 1);
        scanf("%i", &fragmentos[i]);
    }

    for (int i = 1; i < n; i++) {
        int x = fragmentos[i];

        int j;
        for (j = i - 1; j >= 0 && x < fragmentos[j]; j--) {
            fragmentos[j + 1] = fragmentos[j];
        }

        fragmentos[j + 1] = x;
    }

    printf("Ordem: ");
    for (int i = 0; i < n; i++) {
        printf("%i ", fragmentos[i]);
    }
    printf("\n");

    return 0;
}