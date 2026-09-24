#include <stdlib.h>

int* spiralOrder(int** matrix, int matrixSize,
                 int* matrixColSize, int* returnSize)
{
    int m = matrixSize;
    int n = matrixColSize[0];

    int* result = malloc(m * n * sizeof(int));
    *returnSize = 0;

    int top = 0;
    int bottom = m - 1;
    int left = 0;
    int right = n - 1;

    while (top <= bottom && left <= right)
    {
        // Left to right
        for (int j = left; j <= right; j++)
            result[(*returnSize)++] = matrix[top][j];

        top++;

        // Top to bottom
        for (int i = top; i <= bottom; i++)
            result[(*returnSize)++] = matrix[i][right];

        right--;

        // Right to left
        if (top <= bottom)
        {
            for (int j = right; j >= left; j--)
                result[(*returnSize)++] = matrix[bottom][j];

            bottom--;
        }

        // Bottom to top
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
                result[(*returnSize)++] = matrix[i][left];

            left++;
        }
    }

    return result;
}
