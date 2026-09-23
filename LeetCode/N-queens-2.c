#include <stdbool.h>

bool isSafe(int board[], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        // Same column
        if (board[i] == col)
            return false;

        // Same diagonal
        if (board[i] - i == col - row)
            return false;

        // Other diagonal
        if (board[i] + i == col + row)
            return false;
    }

    return true;
}

void solve(int row, int n, int board[], int* count)
{
    if (row == n)
    {
        (*count)++;
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, row, col))
        {
            board[row] = col;

            solve(row + 1, n, board, count);
        }
    }
}

int totalNQueens(int n)
{
    int board[n];
    int count = 0;

    solve(0, n, board, &count);

    return count;
}
