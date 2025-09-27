#include <stdio.h>

typedef struct {
    int resolucao_x;
    int resolucao_y;
    float volume_som;
} Configuracao;

int main() {
    FILE *txt = fopen("./config.txt", "r");

    if (txt == NULL) {
        printf("Erro: Arquivo config.txt nao encontrado!\n");
        return 1;
    }

    Configuracao config;

    fscanf(txt, "%i %i %f", &config.resolucao_x, &config.resolucao_y,
           &config.volume_som);

    printf("Configuracoes carregadas:\nResolucao: %ix%i\nVolume: %.1f\n",
           config.resolucao_x, config.resolucao_y, config.volume_som);

    fclose(txt);
    return 0;
}