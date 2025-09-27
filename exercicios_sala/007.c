#include <stdio.h>
#include <stdlib.h>

void ordernar(int *vetor) {
    int temp;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (vetor[j] < vetor[j + 1]) {
                temp = vetor[j];

                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

int main() {
    int *valores = malloc(sizeof(int) * 3);

    for (int i = 0; i < 3; i++) {
        printf("Insira o valor %i: ", i + 1);
        scanf("%i", valores + i);
    }

    ordernar(valores);

    for (int i = 0; i < 3; i++) {
        printf("%i\n", *(valores + i));
    }

    printf("\n");

    for (int i = 2; i >= 0; i--) {
        printf("%i\n", *(valores + i));
    }

    return 0;
}