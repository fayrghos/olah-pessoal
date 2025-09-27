#include <stdio.h>
#include <string.h>

typedef struct {
    int vida;
    int pontuacao;
} Atributos;

typedef struct {
    char nome[50];
    Atributos stats;
} Personagem;

int main() {
    Personagem jogador;

    char nome_temp[50];
    printf("Insira o nome do jogador: ");
    scanf(" %s", nome_temp);
    strcpy(jogador.nome, nome_temp);

    jogador.stats.vida = 100;
    jogador.stats.pontuacao = 0;

    printf("Nome: %s | Vida: %i | Pontos: %i\n", jogador.nome,
           jogador.stats.vida, jogador.stats.pontuacao);

    jogador.stats.pontuacao += 10;
    jogador.stats.vida -= 25;

    printf("Nome: %s | Vida: %i | Pontos: %i\n", jogador.nome,
           jogador.stats.vida, jogador.stats.pontuacao);

    return 0;
}