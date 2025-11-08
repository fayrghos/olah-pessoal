#include <stdio.h>

int calcular_dano_eco(int n) {
    if (n == 1) {
        return 0;
    }

    if (n == 2) {
        return 1;
    }

    return calcular_dano_eco(n - 1) + calcular_dano_eco(n - 2);
}

int main() {
    int n;

    printf("Insira o número do golpe: ");
    scanf("%i", &n);

    printf("Dano bônus: %i\n", calcular_dano_eco(n));
    return 0;
}