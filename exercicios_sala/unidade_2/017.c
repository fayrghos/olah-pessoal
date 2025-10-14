#include <stdio.h>
#include <stdlib.h>

#define ARQ_LIVROS "./livros_q017.bin"

typedef struct {
    int id;
    char titulo[50];
    int dias_restantes;
} Livro;

int ja_foi_cadastrado(int id) {
    FILE *txt = fopen(ARQ_LIVROS, "rb");
    if (txt == NULL) {
        printf("Arquivo de livros não encontrado!\n");
        exit(1);
    }

    Livro livro_temp;
    while (fread(&livro_temp, sizeof(Livro), 1, txt)) {
        if (livro_temp.id == id) {
            return 1;
        }
    }

    fclose(txt);
    return 0;
}

void cadastrar_livro() {
    int n;

    printf("Insira a quantidade de livros: ");
    scanf("%i", &n);

    // Só criando um arquivo em branco
    FILE *txt = fopen(ARQ_LIVROS, "ab");
    if (txt == NULL) {
        printf("O arquivo de livros falhou em ser criado.");
        exit(1);
    }
    fclose(txt);

    Livro livro_atual;
    for (int i = 0; i < n; i++) {
        printf("  [Livro %i] Insira o ID: ", i + 1);
        scanf("%i", &livro_atual.id);

        if (ja_foi_cadastrado(livro_atual.id)) {
            printf("-- Um livro com esse ID já existe!\n\n");
            continue;
        }

        printf("  [Livro %i] Insira o título: ", i + 1);
        scanf(" %s", livro_atual.titulo);

        printf("  [Livro %i] Insira os dias restantes: ", i + 1);
        scanf("%i", &livro_atual.dias_restantes);

        FILE *txt = fopen(ARQ_LIVROS, "ab");
        fwrite(&livro_atual, sizeof(Livro), 1, txt);
        fclose(txt);

        printf("-- Livro cadastrado!\n\n");
    }
}

void listar_livros() {
    FILE *txt = fopen(ARQ_LIVROS, "rb");
    if (txt == NULL) {
        printf("Arquivo de livros não encontrado!\n");
        exit(1);
    }

    int pelo_menos_um = 0;
    printf("--- Livros Cadastrados ---\n");

    Livro livro_temp;
    while (fread(&livro_temp, sizeof(Livro), 1, txt)) {
        printf("[%s]\n", livro_temp.titulo);
        printf("  ID: %i\n", livro_temp.id);
        printf("  Dias Restantes: %i\n", livro_temp.dias_restantes);
        printf("\n");

        pelo_menos_um = 1;
    }

    if (!pelo_menos_um) {
        printf("  <NENHUM>\n\n");
    }
}

void consultar_livro() {
    FILE *txt = fopen(ARQ_LIVROS, "rb");
    if (txt == NULL) {
        printf("Arquivo de livros não encontrado!\n");
        exit(1);
    }

    int id;
    printf("Insira o ID do livro: ");
    scanf("%i", &id);

    Livro livro_temp;
    while (fread(&livro_temp, sizeof(Livro), 1, txt)) {
        if (livro_temp.id == id) {
            printf("\n");
            printf("[%s]\n", livro_temp.titulo);
            printf("  ID: %i\n", livro_temp.id);
            printf("  Dias restantes: %i\n", livro_temp.dias_restantes);
            printf("\n");
            return;
        }
    }

    printf("-- Livro não encontrado.\n\n");
}

int main() {
    for (;;) {
        printf("--- Menu ---\n");
        printf(" 1 - Cadastrar Livro\n");
        printf(" 2 - Listar Livros\n");
        printf(" 3 - Consultar Livro\n");
        printf(" 4 - Sair\n");
        printf("\n");
        printf("Escolha: ");

        int escolha;
        scanf("%i", &escolha);

        switch (escolha) {
        case 1:
            cadastrar_livro();
            break;

        case 2:
            listar_livros();
            break;

        case 3:
            consultar_livro();
            break;

        case 4:
            printf("Valeu!\n");
            return 0;

        default:
            printf("Escolha Inválida!\n\n");
        }
    }
}