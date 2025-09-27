#include <stdio.h>

typedef struct {
    int posX;
    int posY;
    int moedas;
} Personagem;

void atualizar_personagem(Personagem *ptr_personagem) {
    (*ptr_personagem).posX = 10;
    (*ptr_personagem).posY = 5;
    (*ptr_personagem).moedas++;
}

int main() {
    Personagem jogador = {
        0,
        0,
        0,
    };

    printf("Posicao inicial: (%i, %i) - Moedas: %i\n", jogador.posX,
           jogador.posY, jogador.moedas);

    atualizar_personagem(&jogador);

    printf("Posicao atualizada: (%i, %i) - Moedas: %i\n", jogador.posX,
           jogador.posY, jogador.moedas);

    return 0;
}