#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isSafe(char** board, int row, int col, int n)
{
    // Check column
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 'Q')
            return false;
    }

    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1;
         i >= 0 && j >= 0;
         i--, j--)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1;
         i >= 0 && j < n;
         i--, j++)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    return true;
}

void solve(int row, int n, char** board,
           char*** result, int* returnSize,
           int* returnColumnSizes)
{
    // All queens placed
    if (row == n)
    {
        result[*returnSize] = malloc(n * sizeof(char*));

        for (int i = 0; i < n; i++)
        {
            result[*returnSize][i] =
                malloc((n + 1) * sizeof(char));

            strcpy(result[*returnSize][i], board[i]);
        }

        returnColumnSizes[*returnSize] = n;
        (*returnSize)++;

        return;
    }

    // Try every column in this row
    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, row, col, n))
        {
            board[row][col] = 'Q';

            solve(row + 1, n, board,
                  result, returnSize, returnColumnSizes);

            // Backtrack
            board[row][col] = '.';
        }
    }
}

char*** solveNQueens(int n, int* returnSize,
                     int** returnColumnSizes)
{
    *returnSize = 0;

    // Maximum number of solutions is enough for normal constraints
    char*** result = malloc(10000 * sizeof(char**));
    *returnColumnSizes = malloc(10000 * sizeof(int));

    // Create empty board
    char** board = malloc(n * sizeof(char*));

    for (int i = 0; i < n; i++)
    {
        board[i] = malloc((n + 1) * sizeof(char));

        for (int j = 0; j < n; j++)
            board[i][j] = '.';

        board[i][n] = '\0';
    }

    solve(0, n, board,
          result, returnSize, *returnColumnSizes);

    return result;
}
