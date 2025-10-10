#include <stdio.h>

typedef struct {
    char nome[50];
    int nivel;
    float vida;
    float mana;
} Personagem;

int escolha_menu() {
    printf("--- Menu --- \n");
    printf("  1 - Criar Novo Personagem\n");
    printf("  2 - Sair\n");
    printf("\n");
    printf("Escolha: ");

    int escolha;
    scanf("%i", &escolha);
    return escolha;
}

int main() {
    Personagem person_atual;
    int escolha;

    for (;;) {
        escolha = escolha_menu();

        switch (escolha) {
        case 1:
            printf("Insira o nome do personagem: ");
            scanf(" %s", person_atual.nome);

            printf("Insira o nível do personagem: ");
            scanf("%i", &person_atual.nivel);

            printf("Insira a quantia de vida do personagem: ");
            scanf("%f", &person_atual.vida);

            printf("Insira a quantia de mana do personagem: ");
            scanf("%f", &person_atual.mana);

            FILE *save = fopen("./savegame.sav", "wb");
            fwrite(&person_atual, sizeof(Personagem), 1, save);
            fclose(save);

            printf("\n");
            break;

        case 2:
            printf("Valeu!\n");
            return 0;

        default:
            printf("Escolha inválida!\n");
        }
    }

    return 0;
}