#include <stdio.h>

typedef struct {
    char nome[50];
    int hp;
} Monstro;

int main() {
    int n;
    printf("Insira a quantidade de monstros: ");
    scanf("%i", &n);

    Monstro monstros[n];

    for (int i = 0; i < n; i++) {
        printf("Insira o nome do monstro %i: ", i + 1);
        scanf(" %s", monstros[i].nome);

        printf("  Insira seu HP: ");
        scanf("%i", &monstros[i].hp);
    }

    Monstro mais_fraco = monstros[0];

    for (int i = 1; i < n; i++) {
        if (monstros[i].hp < mais_fraco.hp) {
            mais_fraco = monstros[i];
        }
    }

    printf("\n");
    printf("Alvo prioritario: %s (%i HP)\n", mais_fraco.nome, mais_fraco.hp);
    return 0;
}