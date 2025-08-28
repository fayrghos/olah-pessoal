#include <stdio.h>

void impressor(int *vetor, int tam_vetor) {
    for (int i = 0; i < tam_vetor; i++) {
        printf("%i ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int sala_1[] = {10, 20, 5};
    int sala_2[] = {50, 100};
    int sala_3[] = {5, 5, 5, 10};

    int *ptr_salas[] = {
        sala_1,
        sala_2,
        sala_3,
    };

    printf("Moedas na Sala 1: ");
    impressor(ptr_salas[0], sizeof(sala_1) / sizeof(sala_1[0]));

    printf("Moedas na Sala 2: ");
    impressor(ptr_salas[1], sizeof(sala_2) / sizeof(sala_3[0]));

    printf("Moedas na Sala 3: ");
    impressor(ptr_salas[2], sizeof(sala_3) / sizeof(sala_3[0]));

    return 0;
}