#include <stdio.h>

typedef enum {
    PARADO,
    CORRENDO,
    PULANDO,
} EstadoPersonagem;

int main() {
    EstadoPersonagem estado_atual;

    printf("Insira o estado. 0 = Parado, 1 = Correndo, 2 = Pulando: ");
    scanf("%i", &estado_atual);

    if (estado_atual == PARADO) {
        printf("O personagem está parado.\n");
    }

    else if (estado_atual == CORRENDO) {
        printf("O personagem está correndo!\n");
    }

    else if (estado_atual == PULANDO) {
        printf("O personagem está pulando no ar!\n");
    }

    else {
        printf("Estado inválido!\n");
    }

    return 0;
}