#include <stdio.h>

typedef struct {
    float notas[3];
} Boletim;

typedef struct {
    int matricula;
    char nome[50];
    Boletim boletim;
} Estudante;

typedef struct {
    int quant_a;
    int quant_b;
    int quant_c;
    int quant_d;
    int quant_e;
    int quant_f;
} Conceito;

void incrementar_conceito(float media, Conceito *conceitos) {
    if (media >= 9) {
        conceitos->quant_a++;
    }

    else if (media >= 8) {
        conceitos->quant_b++;
    }

    else if (media >= 7) {
        conceitos->quant_c++;
    }

    else if (media >= 6) {
        conceitos->quant_d++;
    }

    else if (media >= 5) {
        conceitos->quant_e++;
    }

    else {
        conceitos->quant_f++;
    }
}

int main() {
    int n;
    Conceito conceitos = {};

    printf("Insira a quantidade de alunos: ");
    scanf("%i", &n);

    int matricula_atual = 1;

    for (int i = 0; i < n; i++) {
        Estudante estudante_atual;
        float media_atual = 0;

        printf("Insira o nome do Aluno %i: ", i + 1);
        scanf(" %[^\n]s", estudante_atual.nome);

        for (int j = 0; j < 3; j++) {
            printf("  Insira a nota %i de %s: ", j + 1, estudante_atual.nome);
            scanf("%f", &estudante_atual.boletim.notas[j]);

            media_atual += estudante_atual.boletim.notas[j];
        }

        media_atual /= 3;
        incrementar_conceito(media_atual, &conceitos);

        estudante_atual.matricula = matricula_atual++;
    }

    printf("\n");
    printf("Quantidade de A's: %i\n", conceitos.quant_a);
    printf("Quantidade de B's: %i\n", conceitos.quant_b);
    printf("Quantidade de C's: %i\n", conceitos.quant_c);
    printf("Quantidade de D's: %i\n", conceitos.quant_d);
    printf("Quantidade de E's: %i\n", conceitos.quant_e);
    printf("Quantidade de F's: %i\n", conceitos.quant_f);

    return 0;
}