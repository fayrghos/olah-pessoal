#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para os dados do jogador
typedef struct {
    int mat;
    char nome[100];
} Estudante;

// Estrutura do nó da lista
typedef struct No {
    Estudante dado;
    struct No *prox;
} No;

// Estrutura da lista, que contém o ponteiro para o início
typedef struct {
    No *inicio;
} Lista;

// Função para exibir o menu de opções
void menu() {
    printf("\n======== Gerenciador de Party =========\n");
    printf("1 - Adicionar jogador no inicio da party\n");
    printf("2 - Adicionar jogador no fim da party\n");
    printf("5 - Mostrar membros da party\n");
    printf("7 - Remover primeiro jogador da party\n");
    printf("8 - Remover ultimo jogador da party\n");
    printf("9 - Sair\n");
    printf("=======================================\n");
}

// Função para ler os dados de um novo jogador
void ler(Estudante *e) {
    printf("Digite a matricula: ");
    scanf("%d", &e->mat);
    printf("Digite o nome: ");
    scanf(" %[^\n]s", e->nome);
}

// Insere um nó no início da lista
void inserir_inicio(Lista *plista, Estudante dado) {
    No *novo = (No *)malloc(sizeof(No));
    novo->dado = dado;
    novo->prox = plista->inicio;
    plista->inicio = novo;
}

// Insere um nó no fim da lista
void inserir_fim(Lista *plista, Estudante dado) {
    No *novo = (No *)malloc(sizeof(No));
    novo->dado = dado;
    novo->prox = NULL;

    if (plista->inicio == NULL) { // Lista vazia
        plista->inicio = novo;
    } else {
        No *pi;
        for (pi = plista->inicio; pi->prox != NULL; pi = pi->prox)
            ;
        pi->prox = novo;
    }
}

// Mostra todos os elementos da lista
void mostrar(Lista lista) {
    if (lista.inicio == NULL) {
        printf("A party esta vazia!\n");
        return;
    }
    No *pi;
    printf("\n--- Membros da Party ---\n");
    for (pi = lista.inicio; pi != NULL; pi = pi->prox) {
        printf("Matricula: %d | Nome: %s\n", pi->dado.mat, pi->dado.nome);
    }
    printf("------------------------\n");
}

// Deleta o primeiro nó da lista
void deletar_inicio(Lista *plista) {
    if (plista->inicio == NULL) {
        printf("A lista ja esta vazia!\n");
    } else {
        No *pi = plista->inicio;
        plista->inicio = pi->prox;
        free(pi);
    }
}

// Função para deletar o último nó da lista
void deletar_fim(Lista *plista) {
    if (plista->inicio == NULL) {
        printf("A lista está vazia. Não é possível remover jogadores.\n");
        return;
    }

    else if (plista->inicio->prox == NULL) {
        free(plista->inicio);
        plista->inicio = NULL;
        return;
    }

    No *anterior = NULL;
    No *atual = plista->inicio;

    while (atual->prox != NULL) {
        anterior = atual;
        atual = atual->prox;
    }

    free(atual);
    anterior->prox = NULL;
}

int main() {
    Lista lista;
    lista.inicio = NULL;
    int op;

    do {
        menu();
        scanf("%d", &op);

        switch (op) {
        case 1: {
            Estudante e;
            ler(&e);
            inserir_inicio(&lista, e);
            break;
        }
        case 2: {
            Estudante e;
            ler(&e);
            inserir_fim(&lista, e);
            break;
        }
        case 5:
            mostrar(lista);
            break;
        case 7:
            deletar_inicio(&lista);
            break;
        case 8:
            deletar_fim(&lista);
            break;
        case 9:
            printf("Saindo do programa...\n");
            break;
        default:
            printf("Opcao invalida! Tente novamente.\n");
        }

    } while (op != 9);

    return 0;
}