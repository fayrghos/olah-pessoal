#include <stdio.h>

int main() {
    int a, *ptr_a = &a;
    int b, *ptr_b = &b;
    int c, *ptr_c = &c;
    int d, *ptr_d = &d;

    printf("Insira A, B, C e D: ");
    scanf("%i %i %i %i", ptr_a, ptr_b, ptr_c, ptr_d);

    if ((*ptr_b > *ptr_c && *ptr_d > *ptr_a &&
         *ptr_c + *ptr_d > *ptr_a + *ptr_b && *ptr_a % 2 == 0) > 0) {
        printf("Valores aceitos.\n");
        return 0;
    }

    printf("Valores não aceitos.\n");
    return 1;
}