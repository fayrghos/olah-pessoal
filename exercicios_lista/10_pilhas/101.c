#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    int custo_mana;
} Feitico;

typedef struct no {
    Feitico feitico;
    struct no *proximo;
} No;

typedef struct {
    No *topo;
} Pilha;

void inserir(Pilha *pilha) {
    No *novo = malloc(sizeof(No));

    printf("Insira o nome do feitiço: ");
    scanf(" %s", novo->feitico.nome);

    printf("Insira o custo de mana: ");
    scanf("%i", &novo->feitico.custo_mana);

    novo->proximo = pilha->topo;
    pilha->topo = novo;
}

void mostrar_pilha(Pilha *pilha) {
    if (pilha->topo == NULL) {
        printf("A pilha está vazia.\n");
        return;
    }

    No *atual = pilha->topo;
    while (atual != NULL) {
        printf("Feitiço: %s, Custo: %i\n", atual->feitico.nome,
               atual->feitico.custo_mana);

        atual = atual->proximo;
    }
}

int main() {
    Pilha pilha = {};

    for (;;) {
        printf("----------\n");
        printf(" 1 - Adicionar feitiço\n");
        printf(" 2 - Mostrar feitiços\n");
        printf(" 3 - Sair\n");
        printf("----------\n");

        int escolha;
        printf("Escolha: ");
        scanf("%i", &escolha);
        printf("----------\n");
        printf("\n");

        switch (escolha) {
        case 1:
            inserir(&pilha);
            break;

        case 2:
            mostrar_pilha(&pilha);
            break;

        default:
            return 0;
        }
    }
}