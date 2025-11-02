#include <stdio.h>

int calc_dano(int num) {
    if (num <= 1) {
        return num;
    }

    return num + calc_dano(num - 1);
}

int main() {
    int nivel;

    printf("Insira o nível do mago: ");
    scanf("%i", &nivel);

    printf("Dano total: %i\n", calc_dano(nivel));
    return 0;
}