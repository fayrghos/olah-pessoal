#include <stdio.h>
#include <stdlib.h>

int main() {
    int linhas;
    int colunas;

    printf("Insira a quantidade de linhas e colunas: ");
    scanf("%i %i", &linhas, &colunas);

    int **mapa = malloc(sizeof(int *) * linhas);

    for (int i = 0; i < linhas; i++) {
        *(mapa + i) = malloc(sizeof(int) * colunas);
    }

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("Preencha os blocos [0/1/2]: ");
            scanf("%i", &mapa[i][j]);
        }
    }

    int blocos_contados = 0;
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (mapa[i][j] == 1) {
                blocos_contados++;
            }
        }
    }

    printf("O mapa possui %i blocos de tijolo.\n", blocos_contados);

    for (int i = 0; i < linhas; i++) {
        free(*(mapa + i));
    }
    free(mapa);
    return 0;
}