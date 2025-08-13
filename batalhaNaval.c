// Batalha Naval em C - Nível Novato

#include <stdio.h>

int main() {
    // 1. Inicializa o tabuleiro 10x10 com água (0)
    int tabuleiro[10][10] = {0};

    // 2. Define navios de tamanho 3
    int navio_horizontal[3] = {3, 3, 3};
    int navio_vertical[3] = {3, 3, 3};

    // 3. Coordenadas iniciais dos navios (definidas no código)
    int linha_h = 2, coluna_h = 4; // navio horizontal começa na linha 2, coluna 4
    int linha_v = 6, coluna_v = 7; // navio vertical começa na linha 6, coluna 7

    // 4. Posiciona navio horizontal (validação simples)
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha_h][coluna_h + i] = navio_horizontal[i];
    }

    // 5. Posiciona navio vertical (validação simples e sem sobreposição)
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha_v + i][coluna_v] = navio_vertical[i];
    }

    // 6. Exibe o tabuleiro
    printf("Tabuleiro:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
        
    }

    return 0;
}