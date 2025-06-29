#include <stdio.h>

#define TAMANHO 10
#define NAVIO_TAMANHO 3
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

int posicao_livre(int tabuleiro[TAMANHO][TAMANHO], int linha[], int coluna[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (tabuleiro[linha[i]][coluna[i]] != AGUA) {
            return 0;
        }
    }
    return 1;
}

void posicionar_navio(int tabuleiro[TAMANHO][TAMANHO], int linha[], int coluna[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        tabuleiro[linha[i]][coluna[i]] = NAVIO;
    }
}

// Exibe o tabuleiro com símbolos personalizados
void exibir_tabuleiro(int tabuleiro[TAMANHO][TAMANHO], const char* titulo) {
    printf("\n%s\n\n", titulo);
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            if (tabuleiro[i][j] == AGUA) printf(". ");
            else if (tabuleiro[i][j] == NAVIO) printf("N ");
            else if (tabuleiro[i][j] == HABILIDADE) printf("* ");
        }
        printf("\n");
    }
}

// Função para aplicar matriz 5x5
void aplicar_habilidade(int tabuleiro[TAMANHO][TAMANHO], int origem_linha, int origem_coluna, int matriz[][5], int tamanho) {
    int offset = tamanho / 2;
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            if (matriz[i][j] == 1) {
                int linha_t = origem_linha + (i - offset);
                int coluna_t = origem_coluna + (j - offset);

                if (linha_t >= 0 && linha_t < TAMANHO && coluna_t >= 0 && coluna_t < TAMANHO) {
                    if (tabuleiro[linha_t][coluna_t] == AGUA) {
                        tabuleiro[linha_t][coluna_t] = HABILIDADE;
                    }
                }
            }
        }
    }
}

// Matriz Cone (5x5)
void gerar_matriz_cone(int matriz[5][5]) {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            matriz[i][j] = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 2 - i; j <= 2 + i; j++) {
            if (j >= 0 && j < 5) matriz[i][j] = 1;
        }
    }
}

// Matriz Cruz (5x5)
void gerar_matriz_cruz(int matriz[5][5]) {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            matriz[i][j] = (i == 2 || j == 2) ? 1 : 0;
}

// Matriz Octaedro (5x5)
void gerar_matriz_octaedro(int matriz[5][5]) {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            matriz[i][j] = 0;

    matriz[0][2] = 1;
    matriz[1][1] = matriz[1][2] = matriz[1][3] = 1;
    matriz[2][0] = matriz[2][1] = matriz[2][2] = matriz[2][3] = matriz[2][4] = 1;
    matriz[3][1] = matriz[3][2] = matriz[3][3] = 1;
    matriz[4][2] = 1;
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];

    // Inicializa o tabuleiro com água
    for (int i = 0; i < TAMANHO; i++)
        for (int j = 0; j < TAMANHO; j++)
            tabuleiro[i][j] = AGUA;

    // === Fase Novato ===
    int h_linha[] = {2, 2, 2};
    int h_coluna[] = {1, 2, 3};
    int v_linha[] = {4, 5, 6};
    int v_coluna[] = {7, 7, 7};

    if (posicao_livre(tabuleiro, h_linha, h_coluna, NAVIO_TAMANHO))
        posicionar_navio(tabuleiro, h_linha, h_coluna, NAVIO_TAMANHO);
    if (posicao_livre(tabuleiro, v_linha, v_coluna, NAVIO_TAMANHO))
        posicionar_navio(tabuleiro, v_linha, v_coluna, NAVIO_TAMANHO);

    // === Fase Aventureiro ===
    int d1_linha[] = {1, 2, 3};
    int d1_coluna[] = {1, 2, 3};
    int d2_linha[] = {1, 2, 3};
    int d2_coluna[] = {8, 7, 6};

    if (posicao_livre(tabuleiro, d1_linha, d1_coluna, NAVIO_TAMANHO))
        posicionar_navio(tabuleiro, d1_linha, d1_coluna, NAVIO_TAMANHO);
    if (posicao_livre(tabuleiro, d2_linha, d2_coluna, NAVIO_TAMANHO))
        posicionar_navio(tabuleiro, d2_linha, d2_coluna, NAVIO_TAMANHO);

    exibir_tabuleiro(tabuleiro, "Tabuleiro com Navios (Fase Aventureiro)");

    // === Fase Mestre - Habilidades ===
    int cone[5][5], cruz[5][5], octaedro[5][5];

    gerar_matriz_cone(cone);
    gerar_matriz_cruz(cruz);
    gerar_matriz_octaedro(octaedro);

    aplicar_habilidade(tabuleiro, 7, 2, cone, 5);       // Cone em (7,2)
    aplicar_habilidade(tabuleiro, 2, 5, cruz, 5);       // Cruz em (2,5)
    aplicar_habilidade(tabuleiro, 7, 7, octaedro, 5);   // Octaedro em (7,7)

    exibir_tabuleiro(tabuleiro, "Tabuleiro com Habilidades (Fase Mestre)");

    return 0;
}
