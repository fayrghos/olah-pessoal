#include <stdio.h>

typedef struct {
    int matricula;
    char nome[50];
    float notas[3];
} Estudante;

void menu() {
    printf("=== Menu Principal ===\n");
    printf("1 - Cadastrar\n");
    printf("2 - Listar\n");
    printf("3 - Editar\n");
    printf("4 - Verificar Médias\n");
    printf("5 - Maior Média\n");
    printf("0 - Fechar\n");
    printf("======================\n");
    printf("Escolha: ");
}

void menu_editar() {
    printf("=== Editor de Estudante ===\n");
    printf("1 - Nome\n");
    printf("2 - Notas\n");
    printf("0 - Voltar\n");
    printf("===========================\n");
    printf("Escolha: ");
}

void cadastrar(Estudante *estudantes, int *matriculas) {
    printf("Insira o nome do Estudante: ");
    scanf(" %[^\n]s", estudantes[*matriculas].nome);

    for (int i = 0; i < 3; i++) {
        printf("  Insira a nota %i de %s: ", i + 1,
               estudantes[*matriculas].nome);
        scanf("%f", &estudantes[*matriculas].notas[i]);
    }

    (*matriculas)++;
    printf("--- Cadastro concluído!\n\n");
}

void listar(Estudante *estudantes, int *matriculas) {
    if (*matriculas == 0) {
        printf("Nenhum estudante cadastrado.\n\n");
        return;
    }

    printf("--- Lista de Estudantes\n");
    for (int i = 0; i < *matriculas; i++) {
        printf("  [%.04i] %s\n", i + 1, estudantes[i].nome);
    }
    printf("-- Fim da lista\n\n");
}

void editar(Estudante *estudantes, int *matriculas) {
    int desejado;

    printf("Insira o número de matrícula para editar: ");
    scanf("%i", &desejado);

    if (desejado > *matriculas || desejado <= 0) {
        printf("Estudante não encontrado.\n\n");
        return;
    }

    desejado--;

    int escolha = -1;
    while (escolha) {
        printf("\n");
        switch (escolha) {
        case 1:
            printf("Insira o novo nome para %s: ", estudantes[desejado].nome);
            scanf(" %[^\n]s", estudantes[desejado].nome);
            printf("--- Nome alterado!\n\n");
            break;

        case 2:
            for (int i = 0; i < 3; i++) {
                printf("Insira a nova nota %i de %s: ", i + 1,
                       estudantes[desejado].nome);
                scanf(" %f", &estudantes[desejado].notas[i]);
            }
            printf("--- Notas alteradas!\n\n");
            break;
        }

        menu_editar();
        scanf("%i", &escolha);
    }
}

float calcular_media(Estudante estudante) {
    float media = 0;
    for (int i = 0; i < 3; i++) {
        media += estudante.notas[i];
    }
    return media /= 3;
}

void verificar_medias(Estudante *estudantes, int *matriculas) {
    float media_minima;

    printf("Insira a média mínima: ");
    scanf("%f", &media_minima);

    printf("--- Médias maiores ou iguais a %.1f:\n", media_minima);
    for (int i = 0; i < *matriculas; i++) {
        float media_aluno = calcular_media(estudantes[i]);

        if (media_aluno >= media_minima) {
            printf("  - %s (%.1f)\n", estudantes[i].nome, media_aluno);
        }
    }
    printf("--- Fim da lista.\n\n");
}

void maior_media(Estudante *estudantes, int *matriculas) {
    if (*matriculas == 0) {
        printf("Nenhum estudante encontrado.\n\n");
        return;
    }

    Estudante melhor_aluno = estudantes[0];
    float melhor_media = calcular_media(melhor_aluno);

    for (int i = 1; i < *matriculas; i++) {
        float media_atual = calcular_media(estudantes[i]);

        if (media_atual > melhor_media) {
            melhor_media = media_atual;
            melhor_aluno = estudantes[i];
        }
    }

    printf("--- Maior média: %s (%.1f)\n\n", melhor_aluno.nome, melhor_media);
}

int main() {
    Estudante estudantes[1000];
    int matriculas = 0;

    int escolha = -1;
    while (escolha != 0) {
        printf("\n");
        switch (escolha) {
        case 1:
            cadastrar(estudantes, &matriculas);
            break;

        case 2:
            listar(estudantes, &matriculas);
            break;

        case 3:
            editar(estudantes, &matriculas);
            break;

        case 4:
            verificar_medias(estudantes, &matriculas);
            break;

        case 5:
            maior_media(estudantes, &matriculas);
            break;
        }

        menu();
        scanf("%i", &escolha);
    }

    return 0;
}