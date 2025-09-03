#include <stdio.h>

typedef struct {
    int saude;
    int pontuacao;
    int pos_x;
    int pos_y;
} Heroi;

int main() {
    Heroi meu_heroi = {
        100,
        0,
        0,
        0,
    };

    printf("Saúde: %i, Pontuação: %i, X: %i, Y: %i\n\n", meu_heroi.saude,
           meu_heroi.pontuacao, meu_heroi.pos_x, meu_heroi.pos_y);

    Heroi *ptr_heroi = &meu_heroi;

    ptr_heroi->saude -= 25;
    printf("Nova saúde: %i\n", ptr_heroi->saude);

    ptr_heroi->pontuacao += 50;
    printf("Nova pontuação: %i\n", ptr_heroi->pontuacao);

    ptr_heroi->pos_x += 10;
    ptr_heroi->pos_y -= 5;
    printf("Novos X e Y: (%i, %i)\n\n", ptr_heroi->pos_x, ptr_heroi->pos_y);

    printf("Saúde: %i, Pontuação: %i, X: %i, Y: %i\n", ptr_heroi->saude,
           ptr_heroi->pontuacao, ptr_heroi->pos_x, ptr_heroi->pos_y);

    return 0;
}