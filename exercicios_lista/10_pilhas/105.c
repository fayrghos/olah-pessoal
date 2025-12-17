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

void inserir(Pilha *pilha, Feitico dado) {
    No *novo = malloc(sizeof(No));
    novo->feitico = dado;

    novo->proximo = pilha->topo;
    pilha->topo = novo;
}

int vazia(Pilha *pilha) {
    // Anti formatador, ignore
    return pilha->topo == NULL;
}

void mostrar_pilha(Pilha *pilha) {
    if (vazia(pilha)) {
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

Feitico pop(Pilha *pilha) {
    Feitico saida = {.custo_mana = -1};

    if (vazia(pilha)) {
        printf("A pilha de comandos esta vazia!\n");
        return saida;
    }

    No *atual = pilha->topo;
    saida = atual->feitico;

    pilha->topo = atual->proximo;
    free(atual);

    return saida;
}

void liberar_pilha(Pilha *pilha) {
    while (pilha->topo != NULL) {
        pop(pilha);
    }
}

Feitico top(Pilha *pilha) {
    if (vazia(pilha)) {
        printf("A pilha está vazia.\n");
        return (Feitico){.custo_mana = -1};
    }

    return pilha->topo->feitico;
}

void inverter_pilha(Pilha *pilha) {
    Pilha auxiliar = {};

    while (!vazia(pilha)) {
        inserir(&auxiliar, pop(pilha));
    }

    pilha->topo = auxiliar.topo;
}

int main() {
    Pilha pilha = {};
    Feitico feit_temp = {};

    for (;;) {
        printf("----------\n");
        printf(" 1 - Adicionar feitiço\n");
        printf(" 2 - Lançar próximo feitiço\n");
        printf(" 3 - Mostrar feitiços\n");
        printf(" 4 - Consultar próximo feitiço\n");
        printf(" 5 - Verificar status da pilha\n");
        printf(" 6 - Inverter pilha\n");
        printf(" 7 - Sair\n");
        printf("----------\n");

        int escolha;
        printf("Escolha: ");
        scanf("%i", &escolha);
        printf("----------\n");
        printf("\n");

        switch (escolha) {
        case 1:
            printf("Insira o nome do feitiço: ");
            scanf(" %s", feit_temp.nome);

            printf("Insira o custo de mana: ");
            scanf("%i", &feit_temp.custo_mana);

            inserir(&pilha, feit_temp);
            break;

        case 2:
            feit_temp = pop(&pilha);

            if (feit_temp.custo_mana < 0) {
                continue;
            }

            printf("Feitiço '%s' lançado com sucesso!\n", feit_temp.nome);
            break;

        case 3:
            mostrar_pilha(&pilha);
            break;

        case 4:
            feit_temp = top(&pilha);

            if (feit_temp.custo_mana < 0) {
                continue;
            }

            printf("Próximo feitiço: %s, Custo: %i", feit_temp.nome,
                   feit_temp.custo_mana);
            break;

        case 5:
            if (vazia(&pilha)) {
                printf("A pilha de comandos está vazia.\n");
                continue;
            }

            printf("A pilha de comandos possui feitiços pendentes.\n");
            break;

        case 6:
            inverter_pilha(&pilha);
            break;

        default:
            liberar_pilha(&pilha);
            return 0;
        }
    }
}