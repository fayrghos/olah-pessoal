#include <stdio.h>

int main() {
    int balas[2] = {30, 30};
    int granadas[2] = {5, 5};
    int foguetes[2] = {2, 2};

    int *inventario[3] = {
        balas,
        granadas,
        foguetes,
    };

    printf("Balas: %i\n", *inventario[0]);
    printf("Granadas: %i\n", *inventario[1]);
    printf("Foguetes: %i\n", *inventario[2]);

    for (int i = 0; i < 3; i++) {
        **(inventario + i) -= 1;
    }

    printf("Balas: %i\n", *inventario[0]);
    printf("Granadas: %i\n", *inventario[1]);
    printf("Foguetes: %i\n", *inventario[2]);

    return 0;
}