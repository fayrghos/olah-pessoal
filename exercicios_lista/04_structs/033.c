#include <stdio.h>

typedef struct {
    int x;
    int y;
} Posicao;

void mover_personagem(Posicao *ptr_pos, int movimento_x, int movimento_y) {
    (*ptr_pos).x += movimento_x;
    (*ptr_pos).y += movimento_y;
}

int main() {
    Posicao posicao_jogador = {0, 0};
    Posicao *ponteiro_posicao = &posicao_jogador;

    printf("Posicao inicial do jogador: X=%i, Y=%i\n", posicao_jogador.x,
           posicao_jogador.y);

    mover_personagem(&posicao_jogador, 10, 5);

    printf("Posicao final do jogador: X=%i, Y=%i\n", posicao_jogador.x,
           posicao_jogador.y);

    return 0;
}