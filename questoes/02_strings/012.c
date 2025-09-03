#include <stdio.h>
#include <string.h>

int main() {
    char nome_jogador[50];

    printf("Insira o nome do personagem: ");
    scanf("%[^\n]s", nome_jogador);

    if (strlen(nome_jogador) <= 15) {
        printf("Nome valido! Bem-vindo ao jogo, %s!\n", nome_jogador);
        return 0;
    }

    printf("Nome muito longo! Por favor, escolha um nome com ate 15 caracteres.\n");
    return 1;
}