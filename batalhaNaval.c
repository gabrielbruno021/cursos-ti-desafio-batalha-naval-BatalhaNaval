#include <stdio.h>
#include <stdlib.h>

#define TAM 10
#define NAVIO 3
#define AGUA 0
#define HABILIDADE 5

// Função para inicializar a matriz com 0 (água)
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = AGUA;
}

// Função para exibir o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\nTABULEIRO:\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++)
            printf("%2d ", tabuleiro[i][j]);
        printf("\n");
    }
}

// Função para verificar se posição está disponível para o navio
int podePosicionar(int tabuleiro[TAM][TAM], int linha, int coluna, int direcao, int diagonal) {
    for (int i = 0; i < NAVIO; i++) {
        int l = linha + (direcao == 1 ? i : (diagonal == 1 ? i : (diagonal == 2 ? -i : 0)));
        int c = coluna + (direcao == 0 ? i : (diagonal == 1 ? i : (diagonal == 2 ? -i : 0)));
        if (l < 0 || l >= TAM || c < 0 || c >= TAM || tabuleiro[l][c] != AGUA)
            return 0;
    }
    return 1;
}

// Posiciona navios no tabuleiro
void posicionarNavio(int tabuleiro[TAM][TAM], int linha, int coluna, int direcao, int diagonal) {
    for (int i = 0; i < NAVIO; i++) {
        int l = linha + (direcao == 1 ? i : (diagonal == 1 ? i : (diagonal == 2 ? -i : 0)));
        int c = coluna + (direcao == 0 ? i : (diagonal == 1 ? i : (diagonal == 2 ? -i : 0)));
        tabuleiro[l][c] = NAVIO;
    }
}

// Sobrepõe matriz de habilidade ao tabuleiro com valor 5
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[7][7], int origemLinha, int origemColuna) {
    int centro = 3; // centro da matriz de 7x7

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            int l = origemLinha + (i - centro);
            int c = origemColuna + (j - centro);
            if (l >= 0 && l < TAM && c >= 0 && c < TAM && habilidade[i][j] == 1 && tabuleiro[l][c] == AGUA)
                tabuleiro[l][c] = HABILIDADE;
        }
    }
}

// Gera matriz cone
void gerarCone(int cone[7][7]) {
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            cone[i][j] = (j >= 3 - i && j <= 3 + i && i >= 0 && i <= 3) ? 1 : 0;
}

// Gera matriz cruz
void gerarCruz(int cruz[7][7]) {
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            cruz[i][j] = (i == 3 || j == 3) ? 1 : 0;
}

// Gera matriz octaedro
void gerarOctaedro(int octaedro[7][7]) {
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            octaedro[i][j] = (abs(i - 3) + abs(j - 3) <= 3) ? 1 : 0;
}

int main() {
    int tabuleiro[TAM][TAM];
    inicializarTabuleiro(tabuleiro);

    // POSICIONANDO 4 NAVIOS (2 normais + 2 diagonais)
    // Navios são representados com valor 3 no tabuleiro

    // Horizontal - linha 1, coluna 2
    if (podePosicionar(tabuleiro, 1, 2, 0, 0))
        posicionarNavio(tabuleiro, 1, 2, 0, 0);

    // Vertical - linha 4, coluna 5
    if (podePosicionar(tabuleiro, 4, 5, 1, 0))
        posicionarNavio(tabuleiro, 4, 5, 1, 0);

    // Diagonal principal - linha 6, coluna 1
    if (podePosicionar(tabuleiro, 6, 1, 0, 1))
        posicionarNavio(tabuleiro, 6, 1, 0, 1);

    // Diagonal secundária - linha 6, coluna 8
    if (podePosicionar(tabuleiro, 6, 8, 0, 2))
        posicionarNavio(tabuleiro, 6, 8, 0, 2);

    // CRIANDO MATRIZES DE HABILIDADES
    int cone[7][7], cruz[7][7], octaedro[7][7];
    gerarCone(cone);
    gerarCruz(cruz);
    gerarOctaedro(octaedro);

    // Aplicando habilidades em posições fixas
    aplicarHabilidade(tabuleiro, cone, 3, 3);
    aplicarHabilidade(tabuleiro, cruz, 7, 7);
    aplicarHabilidade(tabuleiro, octaedro, 5, 5);

    // EXIBINDO TABULEIRO FINAL
    exibirTabuleiro(tabuleiro);

    return 0;
}
