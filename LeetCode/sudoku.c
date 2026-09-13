#include <stdbool.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize)
{
    int row[9][10] = {0};
    int col[9][10] = {0};
    int box[9][10] = {0};

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == '.')
                continue;

            int num = board[i][j] - '0';

            // Find the 3x3 box number
            int boxNum = (i / 3) * 3 + (j / 3);

            // Check duplicate
            if (row[i][num] ||
                col[j][num] ||
                box[boxNum][num])
            {
                return false;
            }

            row[i][num] = 1;
            col[j][num] = 1;
            box[boxNum][num] = 1;
        }
    }

    return true;
}
