#include <stdio.h>
#include <stdlib.h>
// Projeto: Simulador de Movimentos de Xadrez
// Linguagem: C
// Autor: (patrik sarmento)
// Objetivo: Mostrar como cada peça se move no tabuleiro 8x8
// =========================================


// --------------------------------------------------
// Função para exibir o tabuleiro com uma peça na posição (x, y)
// --------------------------------------------------
void mostrarTabuleiro(int x, int y) {
    printf("\n=== TABULEIRO DE XADREZ (8x8) ===\n");

    for (int i = 0; i < 8; i++) { // percorre as linhas
        for (int j = 0; j < 8; j++) { // percorre as colunas

            // Se a posição atual for onde a peça está, marca com 'P'
            if (i == x && j == y) {
                printf(" P "); // P = posição da peça
            } else {
                printf(" - "); // - = casa vazia
            }
        }
        printf("\n");
    }

    printf("===============================\n");
}

// ===============================
// Peças: Torre, Bispo e Rainha
// ================================

// Movimento da TORRE - anda em linha reta (horizontal e vertical)
void moverTorre(int x, int y) {
    printf("\n=== Movimento da TORRE ===\n");
    printf("A Torre se move em linhas e colunas.\n\n");

    // Movimentos horizontais (mesma linha)
    printf("Movimentos possíveis na linha (horizontal):\n");
    for (int j = 0; j < 8; j++) {
        if (j != y) {
            printf("(%d, %d)\n", x, j);
        }
    }

    // Movimentos verticais (mesma coluna)
    printf("\nMovimentos possíveis na coluna (vertical):\n");
    for (int i = 0; i < 8; i++) {
        if (i != x) {
            printf("(%d, %d)\n", i, y);
        }
    }
}

// Movimento do BISPO - anda nas diagonais
void moverBispo(int x, int y) {
    printf("\n=== Movimento do BISPO ===\n");
    printf("O Bispo se move nas diagonais.\n\n");

    int i, j;

    // Diagonal superior esquerda
    i = x - 1; j = y - 1;
    while (i >= 0 && j >= 0) {
        printf("(%d, %d)\n", i, j);
        i--; j--;
    }

    // Diagonal superior direita
    i = x - 1; j = y + 1;
    while (i >= 0 && j < 8) {
        printf("(%d, %d)\n", i, j);
        i--; j++;
    }

    // Diagonal inferior esquerda
    i = x + 1; j = y - 1;
    while (i < 8 && j >= 0) {
        printf("(%d, %d)\n", i, j);
        i++; j--;
    }

    // Diagonal inferior direita
    i = x + 1; j = y + 1;
    while (i < 8 && j < 8) {
        printf("(%d, %d)\n", i, j);
        i++; j++;
    }
}

// Movimento da RAINHA - combinação da Torre + Bispo
void moverRainha(int x, int y) {
    printf("\n=== Movimento da RAINHA ===\n");
    printf("A Rainha combina os movimentos da Torre e do Bispo.\n\n");

    moverTorre(x, y);
    moverBispo(x, y);
}



// ================================
// Peça: Cavalo
// ================================

void moverCavalo(int x, int y) {
    printf("\n=== Movimento do CAVALO ===\n");
    printf("O Cavalo se move em 'L' (2 casas em uma direção e 1 em outra).\n\n");

    // Todos os 8 movimentos possíveis do cavalo
    int movimentos[8][2] = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    // Verifica quais movimentos estão dentro do tabuleiro
    for (int i = 0; i < 8; i++) {
        int novoX = x + movimentos[i][0];
        int novoY = y + movimentos[i][1];

        if (novoX >= 0 && novoX < 8 && novoY >= 0 && novoY < 8) {
            printf("(%d, %d)\n", novoX, novoY);
        }
    }
}



// ================================
// Movimento Recursivo do Bispo
// ================================

// Função recursiva que continua andando na mesma diagonal
void moverBispoRecursivo(int x, int y, int dx, int dy) {
    // Para a recursão quando sair do tabuleiro
    if (x < 0 || x >= 8 || y < 0 || y >= 8)
        return;

    printf("(%d, %d)\n", x, y);

    // Chamada recursiva para continuar na mesma direção
    moverBispoRecursivo(x + dx, y + dy, dx, dy);
}


// Função que inicia os 4 movimentos diagonais recursivos
void movimentosAvancadosBispo(int x, int y) {
    printf("\n=== Movimento AVANÇADO (Recursivo) do BISPO ===\n");
    printf("Explorando todas as diagonais de forma automática.\n\n");

    moverBispoRecursivo(x - 1, y - 1, -1, -1); // superior esquerda
    moverBispoRecursivo(x - 1, y + 1, -1, +1); // superior direita
    moverBispoRecursivo(x + 1, y - 1, +1, -1); // inferior esquerda
    moverBispoRecursivo(x + 1, y + 1, +1, +1); // inferior direita
}



// ================================
int main() {
    int x = 3, y = 3; // posição inicial da peça no tabuleiro (linha, coluna)

    printf("===========================================\n");
    printf(" Bem-vindo ao Simulador de Movimentos de Xadrez! ♟️\n");
    printf("===========================================\n");

    // Mostra o tabuleiro com a peça posicionada
    mostrarTabuleiro(x, y);

    // Chama os módulos de cada peça
    moverTorre(x, y);
    moverBispo(x, y);
    moverRainha(x, y);
    moverCavalo(x, y);
    movimentosAvancadosBispo(x, y);

    printf("\nFim da simulação! 🏁\n");

    printf("\nPressione ENTER para sair...");
    getchar(); // espera o usuário apertar ENTER antes de encerrar

    return 0;
}
