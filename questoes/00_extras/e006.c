#include <stdio.h>

int main() {
    int quant_estudantes;
    int quant_notas;

    printf("Insira a quantidade de alunos: ");
    scanf("%i", &quant_estudantes);

    printf("Insira a quantidade de notas: ");
    scanf("%i", &quant_notas);

    int notazes[quant_estudantes][quant_notas];

    for (int i = 0; i < quant_estudantes; i++) {
        for (int j = 0; j < quant_notas; j++) {
            printf("Insira a nota %i do aluno %i: ", j + 1, i + 1);
            scanf("%i", &notazes[i][j]);
        }
    }

    int evoluindo;
    for (int i = 0; i < quant_estudantes; i++) {
        evoluindo = 1;
        for (int j = 0; j < quant_notas - 1; j++) {
            if (notazes[i][j] > notazes[i][j + 1]) {
                evoluindo = 0;
            }
        }
        printf("Aluno %i: %sestá evoluindo.\n", i + 1, evoluindo ? "" : "não ");
    }

    return 0;
}