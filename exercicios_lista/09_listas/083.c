#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome[50];
} Jogador;

typedef struct no {
    Jogador jogador;
    struct no *proximo;
} No;

typedef struct {
    struct no *inicio;
} Lista;

void ler_jogador(Jogador *jogador) {
    printf("Insira o ID do jogador: ");
    scanf("%i", &jogador->id);

    printf("Insira o nome do jogador: ");
    scanf(" %s", jogador->nome);
}

void adicionar_inicio(Lista *lista) {
    No *novo = malloc(sizeof(No));
    ler_jogador(&novo->jogador);

    novo->proximo = lista->inicio;
    lista->inicio = novo;
}

void adicionar_final(Lista *lista) {
    No *atual = lista->inicio;

    if (atual == NULL) {
        adicionar_inicio(lista);
        return;
    }

    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }

    No *novo = malloc(sizeof(No));
    ler_jogador(&novo->jogador);
    novo->proximo = NULL;

    atual->proximo = novo;
}

int main() {
    Lista lista = {};

    for (;;) {
        printf("----------\n");
        printf(" 1 - Inserir no Início\n");
        printf(" 2 - Inserir no Final\n");
        printf(" 3 - Mostrar Lista\n");
        printf(" 4 - Sair\n");
        printf("----------\n");
        printf("\n");

        int opcao;
        printf("Escolha: ");
        scanf("%i", &opcao);

        if (opcao == 1) {
            adicionar_inicio(&lista);
        }

        else if (opcao == 2) {
            adicionar_final(&lista);
        }

        else if (opcao == 3) {
            No *atual = lista.inicio;

            while (atual != NULL) {
                printf("[Membro %i] Nome: %s\n", atual->jogador.id,
                       atual->jogador.nome);

                atual = atual->proximo;
            }
        }

        else {
            return 0;
        }
    }
}