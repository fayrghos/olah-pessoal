#include <stdio.h>

int main() {
    int vida_jogador = 100;
    int *ptr_vida = &vida_jogador;

    vida_jogador -= 50;
    printf("O jogador sofreu dano! Vida atual: %i\n", vida_jogador);

    *ptr_vida = 100;
    printf("Power-up coletado! Vida atual: %i\n", vida_jogador);

    return 0;
}