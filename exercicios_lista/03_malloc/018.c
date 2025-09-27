#include <stdio.h>
#include <stdlib.h>

int main() {
    int *vida_inimigo = malloc(sizeof(int));

    if (vida_inimigo == NULL) {
        printf("O ponteiro explodiu.\n");
        return 1;
    }

    *vida_inimigo = 80;
    printf("Um novo inimigo apareceu com %i de vida!\n", *vida_inimigo);

    *vida_inimigo -= 35;
    printf("O jogador atacou! Vida restante do inimigo: %i\n", *vida_inimigo);

    return 0;
}