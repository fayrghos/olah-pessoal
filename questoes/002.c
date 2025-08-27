#include <stdio.h>

int main() {
    int tesouro_local = 0;
    int *plataforma_secreta = &tesouro_local;

    printf("O tesouro ainda nao apareceu. Valor: %i\n", tesouro_local);

    *plataforma_secreta = 1;
    printf("O personagem pisou na plataforma secreta! O tesouro apareceu! Valor: %i\n", tesouro_local);

    return 0;
}