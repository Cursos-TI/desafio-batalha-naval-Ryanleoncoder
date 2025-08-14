// Batalha Naval em C - Nível Aventureiro

#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10
#define NAVIO_TAMANHO 3

int main() {
    // 1. Inicializa o tabuleiro 10x10 com água (0)
    int tabuleiro[LINHAS][COLUNAS] = {0};

    // 2. Define navios de tamanho 3
    int navio_horizontal[NAVIO_TAMANHO] = {3, 3, 3};
    int navio_vertical[NAVIO_TAMANHO] = {3, 3, 3};
    int navio_diag1[NAVIO_TAMANHO] = {3, 3, 3}; // Diagonal principal
    int navio_diag2[NAVIO_TAMANHO] = {3, 3, 3}; // Diagonal secundária

    // 3. Coordenadas iniciais dos navios (definidas no código)
    int linha_h = 2, coluna_h = 4; // horizontal
    int linha_v = 6, coluna_v = 7; // vertical
    int linha_d1 = 0, coluna_d1 = 0; // diagonal principal (tabuleiro[i][i])
    int linha_d2 = 0, coluna_d2 = 9; // diagonal secundária (tabuleiro[i][9-i])

    // 4. Posiciona navio horizontal (validação simples)
    for (int i = 0; i < NAVIO_TAMANHO; i++) {
        // Validação de sobreposição
        if (tabuleiro[linha_h][coluna_h + i] == 0) {
            tabuleiro[linha_h][coluna_h + i] = navio_horizontal[i];
        }
    }

    // 5. Posiciona navio vertical (validação simples)
    for (int i = 0; i < NAVIO_TAMANHO; i++) {
        if (tabuleiro[linha_v + i][coluna_v] == 0) {
            tabuleiro[linha_v + i][coluna_v] = navio_vertical[i];
        }
    }

    // 6. Posiciona navio diagonal principal (tabuleiro[i][i])
    for (int i = 0; i < NAVIO_TAMANHO; i++) {
        int l = linha_d1 + i;
        int c = coluna_d1 + i;
        if (tabuleiro[l][c] == 0) {
            tabuleiro[l][c] = navio_diag1[i];
        }
    }

    // 7. Posiciona navio diagonal secundária (tabuleiro[i][9-i])
    for (int i = 0; i < NAVIO_TAMANHO; i++) {
        int l = linha_d2 + i;
        int c = coluna_d2 - i;
        if (tabuleiro[l][c] == 0) {
            tabuleiro[l][c] = navio_diag2[i];
        }
    }

    // 8. Exibe o tabuleiro
    printf("Tabuleiro:\n");
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}