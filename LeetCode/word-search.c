#include <stdbool.h>
#include <string.h>

bool search(char** board, int m, int n, char* word,
            int i, int j, int index)
{
    if (word[index] == '\0')
        return true;

    if (i < 0 || i >= m || j < 0 || j >= n)
        return false;

    if (board[i][j] != word[index])
        return false;

    char temp = board[i][j];
    board[i][j] = '#';  // Mark as visited

    bool found =
        search(board, m, n, word, i + 1, j, index + 1) ||
        search(board, m, n, word, i - 1, j, index + 1) ||
        search(board, m, n, word, i, j + 1, index + 1) ||
        search(board, m, n, word, i, j - 1, index + 1);

    board[i][j] = temp;  // Restore the cell

    return found;
}

bool exist(char** board, int boardSize, int* boardColSize,
           char* word)
{
    int m = boardSize;
    int n = boardColSize[0];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (search(board, m, n, word, i, j, 0))
                return true;
        }
    }

    return false;
}
