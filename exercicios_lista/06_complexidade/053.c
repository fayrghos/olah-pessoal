#include <stdio.h>

int main() {
    int n;

    printf("Insira a energia inicial do golem: ");
    scanf("%i", &n);

    for (int i = n; i > 1; i /= 2) {
        printf("Energia atual: %i\n", i);
    }

    return 0;
}