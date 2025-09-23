#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    float notas[3];
    int matricula;
} Estudante;

int main() {
    int quant_estudantes;

    float maior = 0;
    char maior_nome[50];

    printf("Insira a quantidade de estudantes: ");
    scanf("%i", &quant_estudantes);

    Estudante estudantes[quant_estudantes];

    for (int i = 0; i < quant_estudantes; i++) {
        estudantes[i].matricula = 0;

        printf("Insira o nome do estudante %i: ", i + 1);
        scanf(" %[^\n]s", estudantes[i].nome);

        for (int j = 0; j < 3; j++) {
            printf("  Insira a nota %i de %s: ", j + 1, estudantes[i].nome);
            scanf("%f", &estudantes[i].notas[j]);

            if (estudantes[i].notas[j] > maior) {
                maior = estudantes[i].notas[j];
                strcpy(maior_nome, estudantes[i].nome);
            }
        }
    }

    printf("\n");
    printf("Maior nota: %.2f\n", maior);
    printf("Estudante: %s\n", maior_nome);
    return 0;
}