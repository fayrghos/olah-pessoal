#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nickname[50];
} Jogador;

typedef struct no {
    Jogador jogador;
    struct no *proximo;
} No;

typedef struct {
    No *inicio;
    No *fim;
} Fila;

void inserir(Fila *fila, Jogador jogador) {
    No *novo = malloc(sizeof(No));
    novo->jogador = jogador;
    novo->proximo = NULL;

    if (fila->inicio == NULL) {
        fila->inicio = novo;
        fila->fim = novo;
        return;
    }

    fila->fim->proximo = novo;
    fila->fim = novo;
}

void mostrar(Fila *fila) {
    if (fila->inicio == NULL) {
        printf("A fila de matchmaking esta vazia.\n");
        return;
    }

    No *aux = fila->inicio;

    while (aux != NULL) {
        printf(" Jogador %i - %s\n", aux->jogador.id, aux->jogador.nickname);

        aux = aux->proximo;
    }
}

Jogador remover(Fila *fila) {
    Jogador saida = {.id = -1};

    if (fila->inicio == NULL) {
        printf("Fila vazia.\n");
        return saida;
    }

    if (fila->inicio->proximo == NULL) {
        saida = fila->inicio->jogador;

        free(fila->inicio);
        fila->inicio = NULL;
        fila->fim = NULL;

        return saida;
    }

    No *atual = fila->inicio;
    fila->inicio = atual->proximo;

    saida = atual->jogador;
    free(atual);
    return saida;
}

int estaVazia(Fila *fila) {
    // Anti formatador, ignore
    return fila->inicio == NULL;
}

Jogador verInicio(Fila *fila) {
    return fila->inicio == NULL ? (Jogador){.id = -1} : fila->inicio->jogador;
}

void salvarFila(Fila *fila, const char *nome_arquivo) {
    FILE *bin = fopen(nome_arquivo, "wb");
    if (bin == NULL) {
        printf("O arquivo falhou ao ser aberto.\n");
        exit(1);
    }

    for (No *atual = fila->inicio; atual != NULL; atual = atual->proximo) {
        fwrite(&atual->jogador, sizeof(Jogador), 1, bin);
    }

    fclose(bin);
}

void carregarFila(Fila *fila, const char *nome_arquivo) {
    FILE *bin = fopen(nome_arquivo, "rb");
    if (bin == NULL) {
        printf("Não foi possível ler o arquivo.\n");
        return;
    }

    Jogador jog_temp = {};
    while (fread(&jog_temp, sizeof(Jogador), 1, bin)) {
        inserir(fila, jog_temp);
    }

    fclose(bin);
}

int main() {
    Fila fila = {};
    Jogador jog_temp = {};

    carregarFila(&fila, "./matchmaking_queue.bin");

    for (;;) {
        printf("----------\n");
        printf(" 1 - Inserir jogador\n");
        printf(" 2 - Mostrar jogadores\n");
        printf(" 3 - Remover jogador\n");
        printf(" 4 - Verificar se a fila esta vazia\n");
        printf(" 5 - Ver quem é o proximo da fila\n");
        printf(" 6 - Salvar fila em arquivo\n");
        printf(" 7 - Sair\n");
        printf("----------\n");

        int escolha;
        printf("Escolha: ");
        scanf("%i", &escolha);
        printf("----------\n");
        printf("\n");

        switch (escolha) {
        case 1:
            printf("Insira o ID do novo jogador: ");
            scanf("%i", &jog_temp.id);

            printf("Insira o nome do novo jogador: ");
            scanf(" %s", jog_temp.nickname);

            inserir(&fila, jog_temp);
            break;

        case 2:
            mostrar(&fila);
            break;

        case 3:
            jog_temp = remover(&fila);

            if (jog_temp.id < 0) {
                continue;
            }

            printf("O jogador %s (ID: %i) foi removido da fila e entrou em uma "
                   "partida.\n",
                   jog_temp.nickname, jog_temp.id);
            break;

        case 4:
            if (estaVazia(&fila)) {
                printf("SIM, a fila está vazia.\n");
                continue;
            }

            printf("NÃO, a fila contém jogadores.\n");
            break;

        case 5:
            jog_temp = verInicio(&fila);

            if (jog_temp.id < 0) {
                printf("A fila está vazia.\n");
                continue;
            }

            printf("O proximo jogador a entrar na partida é: %s (ID: %i)\n",
                   jog_temp.nickname, jog_temp.id);
            break;

        case 6:
            salvarFila(&fila, "./matchmaking_queue.bin");
            break;

        default:
            return 0;
        }
    }
}