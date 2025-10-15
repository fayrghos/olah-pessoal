#include <stdio.h>

typedef struct {
    char tipo[50];
    int hp;
} Inimigo;

int main() {
    int n;

    printf("Insira a quantidade de unidades: ");
    scanf("%i", &n);

    Inimigo unidades[n];
    for (int i = 0; i < n; i++) {
        printf("[Unidade %i] Insira o tipo: ", i + 1);
        scanf(" %s", unidades[i].tipo);

        printf("[Unidade %i] Insira o HP: ", i + 1);
        scanf("%i", &unidades[i].hp);
    }

    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("Inimigo: %s, HP: %i\n", unidades[i].tipo, unidades[i].hp);
    }

    return 0;
}