#include <stdio.h>

char board[3][3];

void initializeBoard() {

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if(j < 2) printf("|");
        }
        printf("\n");
        if(i < 2) printf("---|---|---\n");
    }
}

int checkWin() {

    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return 1;
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return 1;
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return 1;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return 1;
    return 0;
}

int checkDraw() {

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == ' ') return 0;
        }
    }
    return 1;
}

void makeMove(char player) {
    int row, col;
    while(1) {
        printf("Player %c, enter your move (row and column): ", player);
        scanf("%d %d", &row, &col);
        if(row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row-1][col-1] == ' ') {
            board[row-1][col-1] = player;
            break;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
}

int main() {
    char player = 'X';
    initializeBoard();
    while(1) {
        printBoard();
        makeMove(player);
        if(checkWin()) {
            printBoard();
            printf("Player %c wins!\n", player);
            break;
        }
        if(checkDraw()) {
            printBoard();
            printf("It's a draw!\n");
            break;
        }
        player = (player == 'X') ? 'O' : 'X';
    }
    return 0;
}
