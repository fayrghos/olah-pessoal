#include <stdio.h>

typedef struct {
    char nome[50];
    int vida;
    int ataque;
} Inimigo;

int main() {
    FILE *txt = fopen("./wave_data.txt", "r");

    if (txt == NULL) {
        printf("Wave_data não encontrado.");
        return 1;
    }

    Inimigo ini_atual = {};
    Inimigo ini_mforte = {};

    while (fscanf(txt, " %s %i %i", ini_atual.nome, &ini_atual.vida,
                  &ini_atual.ataque) != EOF) {
        if (ini_atual.ataque > ini_mforte.ataque) {
            ini_mforte = ini_atual;
        }
    }

    printf("Maior Ameaça: %s, Vida: %i, Ataque: %i\n", ini_mforte.nome,
           ini_mforte.vida, ini_mforte.ataque);
    return 0;
}