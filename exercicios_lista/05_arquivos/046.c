#include <stdio.h>

typedef struct {
    char nome[50];
    int nivel;
    int high_score;
} PlayerProfile;

// Já que a questão não tem um profiles.dat anexado
void criar_perfis() {
    FILE *dat = fopen("./profiles.dat", "wb");

    PlayerProfile perfis[3] = {
        {"Pedro", 30, 8000},
        {"Carlos", 20, 3000},
        {"Joao", 40, 11000},
    };

    fwrite(perfis, sizeof(PlayerProfile), 3, dat);
    fclose(dat);
}

int main() {
    criar_perfis();

    PlayerProfile perfil_temp;
    FILE *dat = fopen("./profiles.dat", "rb");

    while (fread(&perfil_temp, sizeof(PlayerProfile), 1, dat)) {
        printf("- %s: ", perfil_temp.nome);

        if (perfil_temp.high_score > 10000) {
            printf("Mestre do Jogo\n");
        }

        else if (perfil_temp.high_score > 5000) {
            printf("Veterano\n");
        }

        else {
            printf("Aspirante\n");
        }
    }

    fclose(dat);
    return 0;
}