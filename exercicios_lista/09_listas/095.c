#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char tipo[50];
} Inimigo;

typedef struct no {
    Inimigo inimigo;
    struct no *proximo;
} No;

typedef struct {
    No *inicio;
} Lista;

void adicionar_inicio(Lista *lista, No *novo) {
    novo->proximo = lista->inicio;
    lista->inicio = novo;
}

void adicionar_final(Lista *lista, No *novo) {
    No *atual = lista->inicio;
    if (atual == NULL) {
        adicionar_inicio(lista, novo);
        return;
    }

    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }

    novo->proximo = NULL;
    atual->proximo = novo;
}

void mostrar_itens(Lista *lista) {
    No *atual = lista->inicio;
    if (atual == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    printf("Inimigos:\n");
    while (atual != NULL) {
        printf("  %i - %s\n", atual->inimigo.id, atual->inimigo.tipo);
        atual = atual->proximo;
    }
}

Lista criar_lista(int n) {
    Lista nova_lista = {};

    for (int i = 0; i < n; i++) {
        No *novo = malloc(sizeof(No));

        printf("Insira o ID do inimigo %i: ", i + 1);
        scanf("%i", &novo->inimigo.id);

        printf("Insira o tipo do inimigo %i: ", i + 1);
        scanf(" %s", novo->inimigo.tipo);

        adicionar_final(&nova_lista, novo);
    }

    return nova_lista;
}

int main() {
    Lista lista = {};

    char novo_nome_temp[100];
    int id_desejado;

    for (;;) {
        printf("----------\n");
        printf(" 1 - Criar lista\n");
        printf(" 2 - Exibir lista\n");
        printf(" 3 - Sair\n");
        printf("----------\n");

        int escolha;
        printf("Escolha: ");
        scanf("%i", &escolha);
        printf("----------\n\n");

        switch (escolha) {
        case 1:
            printf("Insira o número de inimigos: ");
            int n;
            scanf("%i", &n);

            if (lista.inicio != NULL) {
                No *atual = lista.inicio;

                while (atual != NULL) {
                    No *temp = atual;
                    atual = atual->proximo;
                    free(temp);
                }
            }

            lista = criar_lista(n);
            break;

        case 2:
            mostrar_itens(&lista);
            break;

        default:
            return 0;
        }
    }
}