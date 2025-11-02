#include <stdio.h>

int calc_cristais(int i, int quant, int vetor[]) {
    if (i == quant) {
        return 0;
    }

    if (vetor[i] > 0) {
        return 1 + calc_cristais(i + 1, quant, vetor);
    }

    return calc_cristais(i + 1, quant, vetor);
}

int main() {
    int quant_cristais;

    printf("Insira a quantidade de cristais: ");
    scanf("%i", &quant_cristais);

    int cristais[quant_cristais];
    calc_cristais(0, quant_cristais - 1, cristais);
}