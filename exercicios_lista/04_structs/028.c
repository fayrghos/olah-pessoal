#include <stdio.h>

struct Jogador {
    float pos_x;
    int pontuacao;
    int tem_pulo_duplo;
};

int main() {
    struct Jogador heroi;

    heroi.pos_x = 50.0;
    heroi.pontuacao = 0;
    heroi.tem_pulo_duplo = 0;

    printf("Posicao X: %.1f, Pontos: %i, Pulo Duplo: %s\n", heroi.pos_x, heroi.pontuacao,
           heroi.tem_pulo_duplo ? "Sim" : "Nao");

    heroi.pontuacao += 10;
    heroi.tem_pulo_duplo = 1;

    printf("Posicao X: %.1f, Pontos: %i, Pulo Duplo: %s\n", heroi.pos_x, heroi.pontuacao,
           heroi.tem_pulo_duplo ? "Sim" : "Nao");

    return 0;
}