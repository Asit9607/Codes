#include <stdio.h>

char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };

void printBoard() {
    printf("  0 1 2\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", i);
        for (int j = 0; j < 3; j++) {
            printf("%c", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("  -----\n");
    }
}

int checkWin(int row, int col) {
    // Check the row
    if (board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
        return 1;
    }
    // Check the column
    if (board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
        return 1;
    }
    // Check the diagonals
    if (row == col && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (row + col == 2 && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }
    return 0;
}

int main() {
    char currentPlayer = 'X';
    int gameWon = 0;
    int moves = 0;

    while (!gameWon && moves < 9) {
        printBoard();
        printf("Player %c, enter your move (row and column): ", currentPlayer);
        int row, col;
        scanf("%d %d", &row, &col);

        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;
            moves++;
            gameWon = checkWin(row, col);

            if (gameWon) {
                printBoard();
                printf("Player %c wins!\n", currentPlayer);
            } else if (moves == 9) {
                printBoard();
                printf("The game is a draw!\n");
            } else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        } else {
            printf("This move is not valid. Try again.\n");
        }
    }

    return 0;
}
