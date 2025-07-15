#include <stdio.h>
#include <stdlib.h>

// Função para imprimir qualquer matriz
void imprimirMatriz(int linhas, int colunas, int matriz[linhas][colunas]) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // ===============================
    // Nível Novato - Tabuleiro 5x5
    // ===============================
    printf("===== Nível Novato =====\n");
    int tabuleiroNovato[5][5] = {0};

    // Navio vertical na coluna 1 (linha 0 a 2)
    for (int i = 0; i < 3; i++) {
        tabuleiroNovato[i][1] = 3;
        printf("Navio vertical em (%d,1)\n", i);
    }

    // Navio horizontal na linha 4 (coluna 0 a 3)
    for (int j = 0; j < 4; j++) {
        tabuleiroNovato[4][j] = 3;
        printf("Navio horizontal em (4,%d)\n", j);
    }

    printf("\nTabuleiro Novato:\n");
    imprimirMatriz(5, 5, tabuleiroNovato);

    // ===============================
    // Nível Aventureiro - Tabuleiro 10x10
    // ===============================
    printf("\n===== Nível Aventureiro =====\n");
    int tabuleiroAventureiro[10][10] = {0};

    // Navio horizontal na linha 2
    for (int j = 1; j <= 4; j++) {
        tabuleiroAventureiro[2][j] = 3;
    }

    // Navio vertical na coluna 6
    for (int i = 5; i <= 8; i++) {
        tabuleiroAventureiro[i][6] = 3;
    }

    // Navio diagonal principal (i == j)
    for (int i = 0; i < 4; i++) {
        tabuleiroAventureiro[i][i] = 3;
    }

    // Navio diagonal secundária (i + j == 9)
    for (int i = 0; i < 4; i++) {
        tabuleiroAventureiro[i][9 - i] = 3;
    }

    printf("\nTabuleiro Aventureiro:\n");
    imprimirMatriz(10, 10, tabuleiroAventureiro);

    // ===============================
    // Nível Mestre - Habilidades Especiais
    // ===============================
    printf("\n===== Nível Mestre =====\n");

    // --- Cone ---
    int cone[3][5] = {0};
    for (int i = 0; i < 3; i++) {
        for (int j = 2 - i; j <= 2 + i; j++) {
            cone[i][j] = 1;
        }
    }

    printf("\nHabilidade: Cone\n");
    imprimirMatriz(3, 5, cone);

    // --- Cruz ---
    int cruz[3][5] = {0};
    for (int i = 0; i < 3; i++) {
        cruz[i][2] = 1; // coluna do meio
    }
    for (int j = 0; j < 5; j++) {
        cruz[1][j] = 1; // linha do meio
    }

    printf("\nHabilidade: Cruz\n");
    imprimirMatriz(3, 5, cruz);

    // --- Octaedro ---
    int octaedro[3][5] = {0};
    int centroX = 1, centroY = 2; // centro da matriz
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (abs(i - centroX) + abs(j - centroY) <= 1) {
                octaedro[i][j] = 1;
            }
        }
    }

    printf("\nHabilidade: Octaedro\n");
    imprimirMatriz(3, 5, octaedro);

    return 0;
}

