#include <stdio.h>
#include <stdlib.h>

typedef enum {
    A,
    B,
    C,
    D,
} Turma;

typedef struct {
    Turma turma;
    float notas[3];
    float frequencia;

    float media;
    int aprovado;
} Boletim;

typedef struct {
    int matricula;
    char nome[50];
    Boletim boletim;
} Aluno;

void ler_aluno(Aluno *aluno) {
    Aluno aluno_temp;

    printf("Insira o nome do novo aluno: ");
    scanf(" %[^\n]s", aluno_temp.nome);

    float media = 0;
    for (int i = 0; i < 3; i++) {
        printf("  Insira a nota %i dele: ", i + 1);
        scanf("%f", &aluno_temp.boletim.notas[i]);

        media += aluno_temp.boletim.notas[i];
    }
    aluno_temp.boletim.media = media /= 3;

    printf("Insira a frequência dele: ");
    scanf("%f", &aluno_temp.boletim.frequencia);

    aluno_temp.boletim.aprovado =
        aluno_temp.boletim.media >= 7 && aluno_temp.boletim.frequencia >= 0.75
            ? 1
            : 0;

    char turma_desejada;
    for (;;) {
        printf("Insira a turma do aluno: ");
        scanf(" %c", &turma_desejada);

        switch (turma_desejada) {
        case 'a':
        case 'A':
            aluno_temp.boletim.turma = A;
            break;

        case 'b':
        case 'B':
            aluno_temp.boletim.turma = B;
            break;

        case 'c':
        case 'C':
            aluno_temp.boletim.turma = C;
            break;

        case 'd':
        case 'D':
            aluno_temp.boletim.turma = D;
            break;

        default:
            printf("--- TURMA INVÁLIDA! ---\n");
            continue;
        }

        break;
    }

    printf("\n");

    *aluno = aluno_temp;
}

char converter_turma(Turma turma) {
    switch (turma) {
    case A:
        return 'A';
    case B:
        return 'B';
    case C:
        return 'C';
    case D:
        return 'D';
    default:
        printf("Turma inválida.\n");
        exit(1);
    }
}

void imprimir_turma(Turma turma, Aluno *alunos, int quant_alunos) {
    printf("--- Estudantes na turma %c:\n", converter_turma(turma));

    Aluno melhor_aluno = {};

    int turma_vazia = 1;
    int melhor_eh_aprovado = 0;

    for (int i = 0; i < quant_alunos; i++) {
        if (alunos[i].boletim.turma == turma) {
            printf("  %s\n", alunos[i].nome);

            if (alunos[i].boletim.aprovado &&
                alunos[i].boletim.media >= melhor_aluno.boletim.media) {
                melhor_aluno = alunos[i];

                melhor_eh_aprovado = 1;
            }

            turma_vazia = 0;
        }
    }

    if (turma_vazia) {
        printf("  <Turma Vazia>\n");
    } else if (melhor_eh_aprovado) {
        printf("  *** Melhor aluno aprovado: %s (Média %.1f)\n",
               melhor_aluno.nome, melhor_aluno.boletim.media);
    } else {
        printf("  *** O melhor aluno não foi aprovado.\n");
    }

    printf("\n");
}

int main() {
    int n;

    printf("Insira a quantidade de alunos: ");
    scanf("%i", &n);

    Aluno alunos[n];

    for (int i = 0; i < n; i++) {
        ler_aluno(&alunos[i]);
    }

    imprimir_turma(A, alunos, n);
    imprimir_turma(B, alunos, n);
    imprimir_turma(C, alunos, n);
    imprimir_turma(D, alunos, n);

    return 0;
}