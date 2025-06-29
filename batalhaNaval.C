#include <stdio.h>

#define TAMANHO 10         // Tamanho fixo do tabuleiro (10x10)
#define NAVIO_TAMANHO 3    // Tamanho fixo dos navios
#define AGUA 0
#define NAVIO 3

int main() {
    int tabuleiro[TAMANHO][TAMANHO]; // Matriz que representa o tabuleiro

    // Inicializa o tabuleiro com água (0)
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Definição das coordenadas iniciais dos navios (definidas diretamente no código)
    int linha_horizontal = 2;
    int coluna_horizontal = 4;

    int linha_vertical = 5;
    int coluna_vertical = 7;

    // Validação se o navio horizontal cabe no tabuleiro
    if (coluna_horizontal + NAVIO_TAMANHO <= TAMANHO) {
        for (int i = 0; i < NAVIO_TAMANHO; i++) {
            // Garante que não há sobreposição
            if (tabuleiro[linha_horizontal][coluna_horizontal + i] != AGUA) {
                printf("Erro: Sobreposição detectada no navio horizontal.\n");
                return 1;
            }
            tabuleiro[linha_horizontal][coluna_horizontal + i] = NAVIO;
        }
    } else {
        printf("Erro: Navio horizontal ultrapassa os limites do tabuleiro.\n");
        return 1;
    }

    // Validação se o navio vertical cabe no tabuleiro
    if (linha_vertical + NAVIO_TAMANHO <= TAMANHO) {
        for (int i = 0; i < NAVIO_TAMANHO; i++) {
            // Garante que não há sobreposição
            if (tabuleiro[linha_vertical + i][coluna_vertical] != AGUA) {
                printf("Erro: Sobreposição detectada no navio vertical.\n");
                return 1;
            }
            tabuleiro[linha_vertical + i][coluna_vertical] = NAVIO;
        }
    } else {
        printf("Erro: Navio vertical ultrapassa os limites do tabuleiro.\n");
        return 1;
    }

    // Exibe o tabuleiro no console
    printf("\nTabuleiro:\n\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
