#include <stdio.h>
#include <stdlib.h>

#define LINHAS 5
#define COLUNAS 10

int main() {
    int *level_map = malloc(sizeof(int) * LINHAS * COLUNAS);

    if (level_map == NULL) {
        printf("O ponteiro explodiu.\n");
        return 1;
    }

    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            if (i == LINHAS - 1) {
                *(level_map + (i * COLUNAS) + j) = 1;
                continue;
            }

            *(level_map + (i * COLUNAS) + j) = 0;
        }
    }

    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("%i ", *(level_map + (i * COLUNAS) + j));
        }
        printf("\n");
    }

    free(level_map);
    return 0;
}