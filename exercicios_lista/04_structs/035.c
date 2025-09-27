#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int valor;
} ItemColetavel;

int main() {
    ItemColetavel inventario[3];

    char string_temp[50];
    for (int i = 0; i < 3; i++) {
        printf("Insira o nome do item %i: ", i + 1);
        scanf(" %s", string_temp);
        strcpy(inventario[i].nome, string_temp);

        printf("Insira o valor do item %i: ", i + 1);
        scanf("%i", &inventario[i].valor);
    }

    ItemColetavel mais_valioso = inventario[0];
    for (int i = 1; i < 3; i++) {
        if (inventario[i].valor > mais_valioso.valor) {
            mais_valioso = inventario[i];
        }
    }

    printf("O item mais valioso coletado foi: %s\n", mais_valioso.nome);
    return 0;
}