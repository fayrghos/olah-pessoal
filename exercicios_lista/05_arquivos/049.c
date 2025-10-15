#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *dat = fopen("./level_1_map.dat", "r");

    if (dat == NULL) {
        printf("ERRO CRITICO: Nao foi possivel carregar os dados do mapa.\n");
        perror("Detalhes do erro");
        exit(1);
    }

    return 0;
}