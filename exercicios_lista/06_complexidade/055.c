#include <stdio.h>

typedef struct {
    int id;
    char nickname[50];
    int pontos_reputacao;
} Jogador;

int buscar_personagem(Jogador *jogadores, int num_jogadores, int id) {
    int ini = 0;
    int fim = num_jogadores - 1;

    while (ini <= fim) {
        int meio = (ini + fim) / 2;

        if (id == jogadores[meio].id) {
            return meio;
        }

        else if (id < jogadores[meio].id) {
            fim = meio - 1;
        }

        else if (id > jogadores[meio].id) {
            ini = meio + 1;
        }
    }

    return -1;
}

int main() {
    int n;

    printf("Insira a quantidade de jogadores: ");
    scanf("%i", &n);

    Jogador jogadores[n];
    for (int i = 0; i < n; i++) {
        printf("[Jogador %i] Insira o ID: ", i + 1);
        scanf("%i", &jogadores[i].id);

        printf("[Jogador %i] Insira o nick do jogador: ", i + 1);
        scanf(" %s", jogadores[i].nickname);

        printf("[Jogador %i] Insira os pontos de reputação: ", i + 1);
        scanf("%i", &jogadores[i].pontos_reputacao);
    }

    int opcao;
    int id_desejado, id_encontrado;

    for (;;) {
        printf("--- Menu ---\n");
        printf(" 1 - Adicionar Reputação\n");
        printf(" 2 - Sair\n");
        printf("\n");

        printf("Escolha: ");
        scanf("%i", &opcao);

        switch (opcao) {
        case 1:
            printf("Insira o ID a ser modificado: ");
            scanf("%i", &id_desejado);

            id_encontrado = buscar_personagem(jogadores, n, id_desejado);
            if (id_encontrado < 0) {
                printf("Jogador com ID %i nao encontrado encontrado.\n\n",
                       id_desejado);
                continue;
            }

            jogadores[id_encontrado].pontos_reputacao += 100;

            printf("Nickname: %s, Nova Reputacao: %i\n\n",
                   jogadores[id_encontrado].nickname,
                   jogadores[id_encontrado].pontos_reputacao);
            break;

        case 2:
            return 0;

        default:
            printf("Opção inválida.\n\n");
        }
    }
}