#include <stdio.h>

int main() {
    int mapa_fase1[5][8] = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 0, 0, 2, 0, 1, 1},
        {0, 0, 1, 1, 0, 1, 0, 0},
        {1, 1, 1, 1, 2, 2, 1, 1},
    };

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 8; j++) {
            if (mapa_fase1[i][j] == 2) {
                printf("Espinho encontrado na linha %i, coluna %i\n", i + 1, j + 1);
            }
        }
    }

    return 0;
}