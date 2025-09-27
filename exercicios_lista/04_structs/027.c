#include <stdio.h>

struct Inimigo {
    int vida;
    int ataque;
    float velocidade;
};

int main() {
    struct Inimigo cogumelo_zumbi;
    struct Inimigo cavaleiro_esqueleto;

    cogumelo_zumbi.vida = 20;
    cogumelo_zumbi.ataque = 5;
    cogumelo_zumbi.velocidade = 0.8;

    cavaleiro_esqueleto.vida = 80;
    cavaleiro_esqueleto.ataque = 15;
    cavaleiro_esqueleto.velocidade = 1.2;

    printf("--- Atributos do Inimigo: Cogumelo Zumbi ---\n");
    printf("Vida: %i\n", cogumelo_zumbi.vida);
    printf("Ataque: %i\n", cogumelo_zumbi.ataque);
    printf("Velocidade: %.1f\n", cogumelo_zumbi.velocidade);

    printf("\n");

    printf("--- Atributos do Inimigo: Cavaleiro Esqueleto ---\n");
    printf("Vida: %i\n", cavaleiro_esqueleto.vida);
    printf("Ataque: %i\n", cavaleiro_esqueleto.ataque);
    printf("Velocidade: %.1f\n", cavaleiro_esqueleto.velocidade);

    return 0;
}