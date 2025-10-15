#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    int vida;
    int ataque;
} Unidade;

int main() {
    int n;

    printf("Insira o número de unidades no esquadrão: ");
    scanf("%i", &n);

    Unidade *esquadrao = malloc(sizeof(Unidade) * n);

    for (int i = 0; i < n; i++) {
        printf("Insira o nome da Unidade %i: ", i + 1);
        scanf(" %s", esquadrao[i].nome);

        printf("Insira a vida da Unidade %i: ", i + 1);
        scanf("%i", &esquadrao[i].vida);

        printf("Insira o ataque da Unidade %i: ", i + 1);
        scanf("%i", &esquadrao[i].ataque);
    }

    FILE *dat = fopen("./squad.dat", "wb");
    fwrite(esquadrao, sizeof(Unidade), n, dat);
    fclose(dat);

    Unidade mais_forte = esquadrao[0];
    for (int i = 1; i < n; i++) {
        if (esquadrao[i].ataque > mais_forte.ataque) {
            mais_forte = esquadrao[i];
        }
    }

    printf("Unidade mais forte: %s\n", mais_forte.nome);
    printf("O ataque dela: %i\n", mais_forte.ataque);

    free(esquadrao);
    return 0;
}