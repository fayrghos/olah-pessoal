#include <stdio.h>
#include <stdlib.h>

int main() {
    int positivos = 0;
    float media;
    float *valores = malloc(sizeof(float) * 6);

    for (int i = 0; i < 6; i++) {
        printf("Insira o valor %i: ", i + 1);
        scanf("%f", valores + i);

        media += *(valores + i);

        if (*(valores + i) > 0) {
            positivos++;
        }
    }

    media /= 6;

    printf("Quantidade de positivos: %i\n", positivos);
    printf("Média: %f\n", media);
    return 0;
}