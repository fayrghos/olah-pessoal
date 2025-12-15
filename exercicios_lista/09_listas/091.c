#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- ESTRUTURAS ---
typedef struct {
    int id;
    char descricao[100];
} Etapa;

typedef struct No {
    Etapa etapa;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
} Lista;

// --- PROTÓTIPOS ---
void menu();
void inserir_fim(Lista *lista, Etapa e);
void mostrar(Lista lista);
void deletar_antes(Lista *lista, int id_ref);

// --- FUNÇÃO PRINCIPAL ---
int main() {
    Lista lista;
    lista.inicio = NULL;
    int op, id_ref;
    Etapa e;

    do {
        menu();
        scanf("%d", &op);
        getchar(); // Limpa o buffer do teclado (o '\n' deixado pelo scanf)

        switch (op) {
        case 1:
            printf("\nDigite o ID da etapa: ");
            scanf("%d", &e.id);
            getchar(); // Limpa o buffer para o fgets
            printf("Digite a descricao da etapa: ");
            fgets(e.descricao, 100, stdin);
            e.descricao[strcspn(e.descricao, "\n")] =
                0; // Remove a nova linha do fgets
            inserir_fim(&lista, e);
            break;
        case 2:
            mostrar(lista);
            break;
        case 3:
            printf("\nInforme o ID da etapa de referencia: ");
            scanf("%d", &id_ref);
            deletar_antes(&lista, id_ref);
            break;
        case 4:
            printf("\nFinalizando o programa...\n");
            break;
        default:
            printf("\nOpcao invalida!\n");
        }
    } while (op != 4);

    // Liberar toda a memória alocada antes de sair (boa prática)
    No *atual = lista.inicio;
    while (atual != NULL) {
        No *temp = atual;
        atual = atual->prox;
        free(temp);
    }

    return 0;
}

// --- IMPLEMENTAÇÃO DAS FUNÇÕES AUXILIARES ---
void menu() {
    printf("\n--- Gerenciador de Etapas de Missao ---\n");
    printf("1 - Inserir etapa no fim\n");
    printf("2 - Mostrar etapas\n");
    printf("3 - Deletar etapa ANTES de um ID\n");
    printf("4 - Sair\n");
    printf("Escolha uma opcao: ");
}

void inserir_fim(Lista *lista, Etapa e) {
    No *novo = (No *)malloc(sizeof(No));
    if (!novo) {
        printf("Erro de alocacao de memoria!\n");
        return;
    }
    novo->etapa = e;
    novo->prox = NULL;

    if (lista->inicio == NULL) {
        lista->inicio = novo;
    } else {
        No *pi = lista->inicio;
        while (pi->prox != NULL) {
            pi = pi->prox;
        }
        pi->prox = novo;
    }
    printf("Etapa '%s' inserida com sucesso!\n", e.descricao);
}

void mostrar(Lista lista) {
    printf("\n--- Diário de Missao ---\n");
    if (lista.inicio == NULL) {
        printf("Nenhuma etapa registrada.\n");
        return;
    }
    No *pi = lista.inicio;
    while (pi != NULL) {
        printf("ID: %d - Descricao: %s\n", pi->etapa.id, pi->etapa.descricao);
        pi = pi->prox;
    }
    printf("------------------------\n");
}

void deletar_antes(Lista *lista, int id_ref) {
    if (lista->inicio == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    else if (lista->inicio->etapa.id == id_ref) {
        printf("Não é possível deletar o primeiro elemento da lista.\n");
        return;
    }

    No *ant_anterior = NULL;
    No *anterior = NULL;
    No *atual = lista->inicio;

    while (atual != NULL) {
        if (atual->etapa.id == id_ref) {
            break;
        }

        ant_anterior = anterior;
        anterior = atual;
        atual = atual->prox;
    }

    // Quando for o segundo
    if (ant_anterior == NULL) {
        free(anterior);
        lista->inicio = atual;
        return;
    }

    if (atual == NULL) {
        printf("ID não encontrado.\n");
        return;
    }

    free(anterior);
    ant_anterior->prox = atual;
}