#include <stdio.h>

typedef struct {
    int pontos;
    float pos_x;
    float pos_y;
} Coletavel;

int main() {
    Coletavel gema_rara;

    printf("Insira os pontos, posição X e posição Y da gema: ");
    scanf("%i %f %f", &gema_rara.pontos, &gema_rara.pos_x, &gema_rara.pos_y);

    printf("Coletável criado! Valor: %i pontos. Posição: (X=%.2f, Y=%.2f)\n",
           gema_rara.pontos, gema_rara.pos_x, gema_rara.pos_y);

    return 0;
}