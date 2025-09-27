#include <stdio.h>

int main() {
    int tamanho;

    printf("Insira o tamanho da matriz: ");
    scanf("%i", &tamanho);

    int matriz[tamanho][tamanho];

    for (int a = 0; a <= tamanho / 2; a++) {
        for (int i = a; i < tamanho - a; i++) {
            for (int j = a; j < tamanho - a; j++) {
                matriz[i][j] = a + 1;
            }
        }
    }

    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            printf("%i ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}