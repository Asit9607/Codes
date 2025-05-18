#include <stdio.h>
#include <stdbool.h>

void printSolution(int board[100][100], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

bool isSafe(int board[100][100], int row, int col, int N) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    return true;
}

bool solveNQueens(int board[100][100], int row, int N) {
    if (row == N) {
        return true;
    }
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col, N)) {
            board[row][col] = 1;
            if (solveNQueens(board, row + 1, N)) {
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
}

int main() {
    int N;
    printf("Enter the value of N: ");
    scanf("%d", &N);

    int board[100][100] = {0};
    
    if (solveNQueens(board, 0, N)) {
        printSolution(board, N);
    } else {
        printf("Solution does not exist.\n");
    }
    return 0;
}
