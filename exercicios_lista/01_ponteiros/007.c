#include <stdio.h>

void ler_cenario(int tam_fileira, int *cenario) {
    for (int i = 0; i < tam_fileira; i++) {
        scanf("%i", cenario + i);
    }
}

int main() {
    int num_blocos;

    printf("Insira o numero de blocos no cenario: ");
    scanf("%i", &num_blocos);

    int cenario[num_blocos];
    ler_cenario(num_blocos, cenario);

    for (int i = 0; i < num_blocos; i++) {
        if (cenario[i] == 1) {
            cenario[i] = 2;
            break;
        }
    }

    printf("Cenario: ");
    for (int i = 0; i < num_blocos; i++) {
        printf("%i ", cenario[i]);
    }
    printf("\n");

    return 0;
}