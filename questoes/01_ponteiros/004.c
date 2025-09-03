#include <stdio.h>

void aplicar_powerup_pontuacao_dupla(int *pontos) {
    *pontos *= 2;
}

int main() {
    int pontuacao_jogador = 1500;
    int *ptr_pontuacao = &pontuacao_jogador;
    printf("Pontuacao antes do power-up: %i\n", pontuacao_jogador);

    aplicar_powerup_pontuacao_dupla(ptr_pontuacao);
    printf("Pontuacao apos o power-up: %i\n", pontuacao_jogador);

    return 0;
}