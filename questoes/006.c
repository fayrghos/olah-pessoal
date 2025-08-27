#include <stdio.h>

int main() {
    int plataformas[] = {10, 20, 5, 15, 30};
    int *ptr_plataforma = plataformas;
    int altura_total = 0;

    for (int i = 0; i < 5; i++) {
        altura_total += *(plataformas + i);
    }

    printf("Altura total do salto: %i metros\n", altura_total);

    return 0;
}