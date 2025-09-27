#include <stdio.h>

int main() {
    int matriz_a[3][2] = {
        {5, 2},
        {3, 5},
        {4, 2},
    };

    int matriz_b[2][2] = {
        {3, 5},
        {2, 4},
    };

    int matriz_result[3][2] = {};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            for (int a = 0; a < 2; a++) {
                matriz_result[i][j] += matriz_a[i][a] * matriz_b[a][j];
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%i ", matriz_result[i][j]);
        }
        printf("\n");
    }

    return 0;
}