#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define ARQ_LIVROS "./livros_q018.bin"

typedef struct {
    int id;
    char titulo[50];
    int dias_restantes;
    int disponibilidade;
} Livro;

int buscar_id(Livro *livros, int q_livros, int id) {
    for (int i = 0; i < q_livros; i++) {
        if (livros[i].id == id) {
            return i;
        }
    }

    return -1;
}

Livro *buscar_inicial(Livro *livros, int q_livros, char inicial,
                      int *q_encontrados) {
    Livro *out = NULL;
    *q_encontrados = 0;

    for (int i = 0; i < q_livros; i++) {
        if (tolower(livros[i].titulo[0]) == tolower(inicial)) {
            out = realloc(out, sizeof(Livro) * (*q_encontrados + 1));
            out[*q_encontrados] = livros[i];

            (*q_encontrados)++;
        }
    }

    return out;
}

int main() {
    int q_livros = 0;
    Livro *livros = NULL;
    Livro livro_temp;

    FILE *save = fopen(ARQ_LIVROS, "rb");
    if (save != NULL) {
        while (fread(&livro_temp, sizeof(Livro), 1, save)) {
            livros = realloc(livros, sizeof(Livro) * (q_livros + 1));
            livros[q_livros] = livro_temp;
            q_livros++;
        }
        fclose(save);
    }

    for (;;) {
        int escolha_int;
        char escolha_char;

        printf("--- Menu ---\n");
        printf(" 1 - Verificar disponibilidade\n");
        printf(" 2 - Procurar usando inicial\n");
        printf(" 3 - Encontrar o menor número de dias em intervalo\n");
        printf(" 4 - Inserir novo livro\n");
        printf(" 5 - Sair\n");
        printf("\n");

        printf("Escolha: ");
        scanf("%i", &escolha_int);

        switch (escolha_int) {
        case 1:
            printf("Insira o ID do livro: ");
            scanf("%i", &escolha_int);

            int id = buscar_id(livros, q_livros, escolha_int);

            if (id < 0) {
                printf("-- Livro não encontrado!\n\n");
                continue;
            }

            livro_temp = livros[id];

            printf("\n");
            printf("--- Livro encontrado: \"%s\"\n", livro_temp.titulo);
            printf("  Dias Restantes: %i\n", livro_temp.dias_restantes);
            printf("  Disponibilidade: %s\n",
                   livro_temp.disponibilidade ? "Disponível" : "Indisponível");
            printf("\n");
            break;

        case 2:
            printf("Insira a inicial desejada: ");
            scanf(" %c", &escolha_char);

            int q_encontrados = 0;
            Livro *encontrados =
                buscar_inicial(livros, q_livros, escolha_char, &q_encontrados);

            if (encontrados == NULL) {
                printf("\n-- Nenhum livro foi encontrado.\n\n");
                continue;
            }

            printf("\n-- Livros encontrados: %i\n", q_encontrados);
            for (int i = 0; i < q_encontrados; i++) {
                printf("  - %s (ID %i)\n", encontrados[i].titulo,
                       encontrados[i].id);
            }
            printf("\n");

            free(encontrados);
            break;

        case 3:
            printf("Insira o ID inicial: ");
            int id_a;
            scanf("%i", &id_a);

            printf("Insira o ID final: ");
            int id_b;
            scanf("%i", &id_b);

            if (id_a < 0 || id_a >= q_livros || id_b < 0 || id_b >= q_livros) {
                printf("Intervalo de IDs inválido!\n\n");
                continue;
            }

            Livro menor_dias_restantes = livros[id_a];
            for (int i = id_a; i <= id_b; i++) {
                if (livros[i].dias_restantes <
                    menor_dias_restantes.dias_restantes) {
                    menor_dias_restantes = livros[i];
                }
            }

            printf("\n");
            printf("-- Menor dias restantes no intervalo de IDs [%i, %i]:\n",
                   id_a, id_b);
            printf("  ID: %i\n", menor_dias_restantes.id);
            printf("  Nome: %s\n", menor_dias_restantes.titulo);
            printf("  Dias Restantes: %i\n",
                   menor_dias_restantes.dias_restantes);
            printf("\n");
            break;

        case 4:
            printf("Insira o nome do novo livro: ");
            scanf(" %s", livro_temp.titulo);

            printf("Insira a quantidade de dias restantes: ");
            scanf("%i", &livro_temp.dias_restantes);

            printf("Insira a disponibilidade [0/1]: ");
            scanf("%i", &livro_temp.disponibilidade);

            livro_temp.id = q_livros;

            printf("\n");

            livros = realloc(livros, sizeof(Livro) * (q_livros + 1));
            livros[q_livros] = livro_temp;
            q_livros++;

            save = fopen(ARQ_LIVROS, "wb");
            if (save == NULL) {
                printf("Ocorreu um erro ao salvar!\n");
                return 1;
            }

            fwrite(livros, sizeof(Livro), q_livros, save);
            fclose(save);
            break;

        case 5:
            printf("Tchau!\n");
            return 0;

        default:
            printf("Opção inválida.\n");
        }
    }

    return 0;
}