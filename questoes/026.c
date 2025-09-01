#include <stdio.h>
#include <stdlib.h>

int main() {
    int *mochila = malloc(sizeof(int) * 3);

    for (int i = 0; i < 3; i++) {
        printf("Insira o valor do item %i: ", i + 1);
        scanf("%i", mochila + i);
    }

    printf("Itens na mochila: ");
    for (int i = 0; i < 3; i++) {
        printf("%i ", *(mochila + i));
    }
    printf("\n");

    mochila = realloc(mochila, sizeof(int) * 6);

    for (int i = 3; i < 6; i++) {
        printf("Insira o valor do item %i: ", i + 1);
        scanf("%i", mochila + i);
    }

    printf("Itens na mochila: ");
    for (int i = 0; i < 6; i++) {
        printf("%i ", *(mochila + i));
    }
    printf("\n");

    free(mochila);
    return 0;
}