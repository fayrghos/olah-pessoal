#include <stdio.h>

typedef struct {
    char nome[50];
    int vida;
    int ataque;
} Campeao;

int main() {
    Campeao esquadrao[3];

    FILE *dat = fopen("./squad.dat", "rb");
    fread(esquadrao, sizeof(Campeao), 3, dat);
    fclose(dat);

    Campeao mais_tanque = esquadrao[0];
    for (int i = 1; i < 3; i++) {
        if (esquadrao[i].vida > mais_tanque.vida) {
            mais_tanque = esquadrao[i];
        }
    }

    printf("Tanque do esquadrão: %s\n", mais_tanque.nome);
    return 0;
}