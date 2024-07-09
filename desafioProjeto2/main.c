#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Função para inicializar o tabuleiro
void inicializarTabuleiro(char tabuleiro[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(char tabuleiro[3][3]) {
    printf("\n  3   2   1 \n");
    printf("1 %c | %c | %c \n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
    printf(" ---|---|---\n");
    printf("2 %c | %c | %c \n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
    printf(" ---|---|---\n");
    printf("3 %c | %c | %c \n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
}

// Função para fazer uma jogada
int fazerJogada(char tabuleiro[3][3], int linha, int coluna, char jogador) {
    if(tabuleiro[linha][coluna] == ' ') {
        tabuleiro[linha][coluna] = jogador;
        return 1;
    } 

    return 0;
}

// Função para verificar vitória
int verificarVitoria(char tabuleiro[3][3], char jogador) {
    for(int i = 0; i < 3; i++) {
        if(tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador)
            return 1;
        if(tabuleiro[0][i] == jogador && tabuleiro[1][i] == jogador && tabuleiro[2][i] == jogador)
            return 1;
    }
    if(tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador)
        return 1;
    if(tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador)
        return 1;
        
    return 0;
}

int main(void) {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    char tabuleiro[3][3];
    int linha, coluna, jogadas = 0;
    char jogador = 'X';
    
    inicializarTabuleiro(tabuleiro);
    
    while(1) {
        exibirTabuleiro(tabuleiro);
        printf("\nJogador %c, digite a linha (0-2) e a coluna (0-2): ", jogador);
        scanf("%d %d", &linha, &coluna);
        
        if(fazerJogada(tabuleiro, linha, coluna, jogador)) {
            jogadas++;
            if(verificarVitoria(tabuleiro, jogador)) {
                exibirTabuleiro(tabuleiro);
                printf("\nO jogador %c venceu!\n", jogador);
                break;
            }
            if(jogadas == 9) {
                exibirTabuleiro(tabuleiro);
                printf("\nO jogo deu velha!\n");
                break;
            }
            jogador = (jogador == 'X') ? 'O' : 'X';
        } else {
            printf("Posição inválida! Tente novamente.\n");
        }
    }
    
    return 0;
}
