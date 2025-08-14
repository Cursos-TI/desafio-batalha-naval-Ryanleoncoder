// Batalha Naval em C - Nível Aventureiro

#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10
#define NAVIO_TAMANHO 3

int main() {
    // 1. Inicializa o tabuleiro 10x10 com água (0)
    int tabuleiro[LINHAS][COLUNAS] = {0};

    // 2. Coordenadas iniciais dos navios (definidas no código)
    int linha_h = 2, coluna_h = 4; // horizontal
    int linha_v = 6, coluna_v = 7; // vertical
    int linha_d1 = 0, coluna_d1 = 0; // diagonal principal (tabuleiro[i][i])
    int linha_d2 = 0, coluna_d2 = 9; // diagonal secundária (tabuleiro[i][9-i])

    // 3. Posiciona navio horizontal (com validação de limites e sobreposição)
    for (int i = 0; i < NAVIO_TAMANHO; i++) {
        int current_col = coluna_h + i;
        if (linha_h < LINHAS && current_col < COLUNAS && tabuleiro[linha_h][current_col] == 0) {
            tabuleiro[linha_h][current_col] = 3;
        }
    }

    // 4. Posiciona navio vertical (com validação de limites e sobreposição)
    for (int i = 0; i < NAVIO_TAMANHO; i++) {
        int current_lin = linha_v + i;
        if (current_lin < LINHAS && coluna_v < COLUNAS && tabuleiro[current_lin][coluna_v] == 0) {
            tabuleiro[current_lin][coluna_v] = 3;
        }
    }

    // 5. Posiciona navio diagonal principal (com validação de limites e sobreposição)
    for (int i = 0; i < NAVIO_TAMANHO; i++) {
        int l = linha_d1 + i;
        int c = coluna_d1 + i;
        if (l < LINHAS && c < COLUNAS && tabuleiro[l][c] == 0) {
            tabuleiro[l][c] = 3;
        }
    }

    // 6. Posiciona navio diagonal secundária (com validação de limites e sobreposição)
    for (int i = 0; i < NAVIO_TAMANHO; i++) {
        int l = linha_d2 + i;
        int c = coluna_d2 - i;
        if (l < LINHAS && c >= 0 && tabuleiro[l][c] == 0) {
            tabuleiro[l][c] = 3;
        }
    }

    // 7. Exibe o tabuleiro
    printf("Tabuleiro:\n");
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}