#include <stdio.h>

int verificarGanhador(char tabuleiro[3][3], char jogadorAtual) {

    for (int i = 0; i < 3; i++) {

        if (tabuleiro[i][0] == jogadorAtual && tabuleiro[i][1] == jogadorAtual && tabuleiro[i][2] == jogadorAtual) {

            return 1;

        }

    }

    for (int i = 0; i < 3; i++) {

        if (tabuleiro[0][i] == jogadorAtual && tabuleiro[1][i] == jogadorAtual && tabuleiro[2][i] == jogadorAtual) {

            return 1;

        }

    }

    if (tabuleiro[0][0] == jogadorAtual && tabuleiro[1][1] == jogadorAtual && tabuleiro[2][2] == jogadorAtual) {

        return 1;

    }

    if (tabuleiro[0][2] == jogadorAtual && tabuleiro[1][1] == jogadorAtual && tabuleiro[2][0] == jogadorAtual) {

        return 1;

    }

    return 0;

}

int verificarPosicao(char tabuleiro[3][3], int linha, int coluna) {

    if (tabuleiro[linha][coluna] == 'X' || tabuleiro[linha][coluna] == 'O') {

        return 0;

    }

    return 1;

}

void mostrarTabuleiro(char tabuleiro[3][3]){

    printf("\n");

    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            if (j == 1) {

                printf("|%c|", tabuleiro[i][j]);

            } else {

                printf("%c", tabuleiro[i][j]);

            }

        }

        printf("\n");

    }

    printf("\n");

}

int main() {

    char tabuleiro[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    int rodadas = 9;

    char jogadorAtual = 'X';
    
    while (rodadas) {
    
        int posicao;

        mostrarTabuleiro(tabuleiro);

        printf("Digite a posicao para %c: ", jogadorAtual);
        scanf("%d", &posicao);

        int linha = (posicao - 1) / 3;
        
        int coluna = (posicao - 1) % 3;

        if (verificarPosicao(tabuleiro, linha, coluna)) {

            tabuleiro[linha][coluna] = jogadorAtual;

        } else {

            printf("Opcao ja selecionada!\n");
            
            continue;

        }

        if (verificarGanhador(tabuleiro, jogadorAtual)) {

            mostrarTabuleiro(tabuleiro);

            printf("O Ganhador foi %c!!!\n", jogadorAtual);

            break;

        }

        jogadorAtual = jogadorAtual == 'X' ? 'O' : 'X';

        rodadas--;

        if (!rodadas) {

            printf("\nO Jogo Empatou!!\n");

        }

    }

    return 0;

}