#include <stdio.h>

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

char player = 'X';

void displayBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void play() {
    int row, col;
    while (1) {
        displayBoard();
        printf("Player %c turn\n", player);
        printf("Enter row (1-3) and column (1-3) to place your %c: ", player);
        scanf("%d %d", &row, &col);
        if (row > 3 || col > 3) {
            printf("Invalid move! Please try again\n");
            continue;
        }
        row--;
        col--;
        if (board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = player;
        } else {
            printf("Place already filled! Please try again\n");
            continue;
        }

        if ((board[0][0] == board[1][1] && board[0][0] == board[2][2]) ||
            (board[0][2] == board[1][1] && board[0][2] == board[2][0])) {   //checking digonals
            if (board[1][1] == 'X') {
                printf("X wins\n");
                break;
            } else {
                printf("O wins\n");
                break;
            }
        }

        for (int i = 0; i < 3; i++) {
            if ((board[i][0] == board[i][1] && board[i][0] == board[i][2]) ||
                (board[0][i] == board[1][i] && board[0][i] == board[2][i])) {       //chcekcing row and column
                if (board[i][0] == 'X') {
                    printf("X wins\n");
                    return;
                } else {
                    printf("O wins\n");
                    return;
                }
            }
        }

        if (player == 'X')
            player = 'O';
        else
            player = 'X';
    }
}

int main() {
    printf("Tic Tac Toe Game\n");
    printf("Player 1 (X)  -  Player 2 (O)\n\n");
    play();
    return 0;
}

