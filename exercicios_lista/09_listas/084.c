#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char titulo[50];
    char status[50];
} Missao;

typedef struct no {
    Missao missao;
    struct no *proximo;
} No;

typedef struct {
    No *inicial;
} Lista;

void ler_missao(Missao *missao) {
    printf("Insira o ID da missão: ");
    scanf("%i", &missao->id);

    printf("Insira o título da missão: ");
    scanf(" %s", missao->titulo);

    printf("Insira o status da missão: ");
    scanf(" %s", missao->status);
}

void adicionar_inicio(Lista *lista) {
    No *novo = malloc(sizeof(No));
    ler_missao(&novo->missao);

    novo->proximo = lista->inicial;
    lista->inicial = novo;
}

void adicionar_final(Lista *lista) {
    No *atual = lista->inicial;

    if (atual == NULL) {
        adicionar_inicio(lista);
        return;
    }

    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }

    No *novo = malloc(sizeof(No));
    ler_missao(&novo->missao);
    novo->proximo = NULL;

    atual->proximo = novo;
}

No *pesquisar_missao(Lista *lista, int id_desejado) {
    No *atual = lista->inicial;

    if (atual == NULL) {
        return NULL;
    }

    while (atual != NULL && atual->missao.id != id_desejado) {
        atual = atual->proximo;
    }

    return atual;
}

void mostrar_missoes(Lista *lista) {
    No *atual = lista->inicial;

    while (atual != NULL) {
        printf("[Missão %i] Título: %s, Status: %s\n", atual->missao.id,
               atual->missao.titulo, atual->missao.status);

        atual = atual->proximo;
    }
}

int main() {
    Lista lista = {};

    for (;;) {
        printf("--------------------\n");
        printf(" 1 - Adicionar Missão\n");
        printf(" 2 - Mostrar Missões\n");
        printf(" 3 - Buscar Missão por ID\n");
        printf(" 4 - Sair\n");
        printf("--------------------\n");
        printf("\n");

        int opcao;
        printf("Escolha: ");
        scanf("%i", &opcao);

        if (opcao == 1) {
            adicionar_final(&lista);
        }

        else if (opcao == 2) {
            mostrar_missoes(&lista);
        }

        else if (opcao == 3) {
            int desejado;
            printf("Insira o ID desejado: ");
            scanf("%i", &desejado);

            No *encontrado = pesquisar_missao(&lista, desejado);

            if (encontrado == NULL) {
                printf("Missão não encontrada.\n");
                continue;
            }

            printf("[Missão %i] Título: %s, Status: %s\n",
                   encontrado->missao.id, encontrado->missao.titulo,
                   encontrado->missao.status);
        }

        else {
            return 0;
        }
    }
}