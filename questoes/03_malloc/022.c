#include <stdio.h>
#include <stdlib.h>

int main() {
    int n_inimigos;
    int *ptr_onda;

    printf("Insira a quantiade de inimigos na onda: ");
    scanf("%i", &n_inimigos);

    ptr_onda = malloc(sizeof(int) * n_inimigos);

    for (int i = 0; i < n_inimigos; i++) {
        printf("Digite o ID do inimigo %i: ", i + 1);
        scanf("%i", ptr_onda + i);
    }

    printf("Onda de inimigos criada com sucesso! IDs: ");
    for (int i = 0; i < n_inimigos; i++) {
        printf("%i ", *(ptr_onda + i));
    }
    printf("\n");

    return 0;
}