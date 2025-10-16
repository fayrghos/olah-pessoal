#include <stdio.h>

typedef struct {
    int id;
    char nome[50];
    int forca;
    int agilidade;
    int inteligencia;
} Personagem;

int buscar_personagem(Personagem *persons, int num_persons, int id) {
    for (int i = 0; i < num_persons; i++) {
        if (persons[i].id == id) {
            return i;
        }
    }

    return -1;
}

int main() {
    int num_persons;

    printf("Insira a quantidade de personagens: ");
    scanf("%i", &num_persons);

    Personagem persons[num_persons];

    for (int i = 0; i < num_persons; i++) {
        printf("Insira o ID do personagem %i: ", i + 1);
        scanf("%i", &persons[i].id);

        printf("Insira o nome desse personagem: ");
        scanf(" %s", persons[i].nome);

        printf("Insira os atributos de força, agilidade e inteligência: ");
        scanf("%i %i %i", &persons[i].forca, &persons[i].agilidade,
              &persons[i].inteligencia);
    }
    printf("\n");

    int opcao;
    int id;

    for (;;) {
        printf("--- Menu ---\n");
        printf(" 1 - Consultar Personagem\n");
        printf(" 2 - Sair\n");
        printf("\n");

        printf("Escolha: ");
        scanf("%i", &opcao);

        switch (opcao) {
        case 1:
            printf("Insira o ID do personagem: ");
            scanf("%i", &id);

            id = buscar_personagem(persons, num_persons, id);
            if (id < 0) {
                printf("O personagem não existe.\n\n");
                continue;
            }

            float media_atribs = persons[id].forca + persons[id].agilidade +
                                 persons[id].inteligencia;
            media_atribs /= 3.0;

            printf("Personagem: %s\n", persons[id].nome);
            printf("Média dos atributos: %.2f\n\n", media_atribs);
            break;

        case 2:
            return 0;

        default:
            printf("Opção inválida.\n\n");
        }
    }

    return 0;
}