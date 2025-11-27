#include "combate.h"

int calcular_ataque_total(int ataque_base, int bonus_arma) {
    return ataque_base + bonus_arma;
}

int aplicar_dano(int vida_atual, int dano_sofrido) {
    return vida_atual - dano_sofrido;
}