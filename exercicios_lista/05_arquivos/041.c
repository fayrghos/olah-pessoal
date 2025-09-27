#include <stdio.h>

int main() {
    int opcao = -1;
    char evento[50];

    FILE *txt = fopen("./game_log.txt", "a");

    for (;;) {
        printf("--- Menu ---\n");
        printf("  1 - Registrar novo evento\n");
        printf("  2 - Fechar\n");
        printf("Escolha: ");
        scanf("%i", &opcao);

        if (opcao != 1) {
            break;
        }

        printf("Insira o evento: ");
        scanf(" %s", evento);

        fprintf(txt, "%s\n", evento);
    }

    fclose(txt);
    return 0;
}