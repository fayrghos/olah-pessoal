#include <stdio.h>
#include <stdlib.h>

int main() {
    float *ptr_altura_salto_duplo = NULL;

    printf("Jogador ainda nao possui o Salto Duplo.\n");

    ptr_altura_salto_duplo = malloc(sizeof(float));
    if (ptr_altura_salto_duplo == NULL) {
        printf("O ponteiro explodiu.\n");
        return 1;
    }

    *ptr_altura_salto_duplo = 15.5;

    printf("Pena Dourada coletada! Altura do Salto Duplo: %.2f\n", *ptr_altura_salto_duplo);
    return 0;
}