#include "personagem.h"
#include <stdio.h>

int main() {
    int n;
    printf("Insira a quantidade de membros na equipe: ");
    scanf("%i", &n);

    Personagem *party = cria_party(n);

    registra_membros(party, n);
    exibe_relatorio(party, n);

    libera_party(party);
    return 0;
}