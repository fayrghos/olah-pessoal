#include <stdio.h>

int main() {
    int pontuacao = 0;
    int *ptr_pontuacao = &pontuacao;

    printf("Pontuacao inicial: %i\n", pontuacao);

    for (int i = 0; i < 3; i++) {
        *ptr_pontuacao += 10;
    }

    printf("Pontuacao final apos coletar 3 moedas: %i\n", pontuacao);

    return 0;
}