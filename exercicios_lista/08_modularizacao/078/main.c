#include "combate.h"
#include <stdio.h>

int main() {
    int ataque_base;
    printf("Insira o dano de ataque base: ");
    scanf("%i", &ataque_base);

    int bonus_espada;
    printf("Insira o bonûs de dano da espada: ");
    scanf("%i", &bonus_espada);

    int vida_inimigo;
    printf("Insira a vida do inimigo: ");
    scanf("%i", &vida_inimigo);

    int ataque_total = calcular_ataque_total(ataque_base, bonus_espada);

    printf("Ataque total do herói: %i\n", ataque_total);
    printf("Vida restant do inimigo: %i\n",
           aplicar_dano(vida_inimigo, ataque_total));

    return 0;
}