#include <stdio.h>
#include <string.h>

int main() {
    char inventario[5][19];
    char necessario[50];

    for (int i = 0; i < 5; i++) {
        printf("Insira o nome do item %i: ", i + 1);
        scanf(" %s", inventario + i);
    }

    printf("Insira o nome do item necessário para abrir a porta: ");
    scanf(" %s", necessario);

    for (int i = 0; i < 5; i++) {
        if (strcmp(inventario[i], necessario) == 0) {
            printf("Porta aberta\n!");
            return 0;
        }
    }

    printf("Você não tem o item necessário.\n");
    return 1;
}