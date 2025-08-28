#include <stdio.h>
#include <string.h>

int main() {
    char nome_jogador[50];
    char titulo_conquistado[50];

    printf("Insira o nome do herói: ");
    scanf(" %s", nome_jogador);

    printf("Insira o título conquistado: ");
    scanf(" %s", titulo_conquistado);

    strcat(nome_jogador, " ");
    strcat(nome_jogador, titulo_conquistado);

    printf("O herói agora é conhecido como: %s\n", nome_jogador);
    return 0;
}