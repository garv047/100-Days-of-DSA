#include <stdlib.h>

int compare(const void* a, const void* b)
{
    int* x = *(int**)a;
    int* y = *(int**)b;

    return x[0] - y[0];
}

int** merge(int** intervals, int intervalsSize,
            int* intervalsColSize, int* returnSize,
            int** returnColumnSizes)
{
    qsort(intervals, intervalsSize, sizeof(int*), compare);

    int** result = malloc(intervalsSize * sizeof(int*));
    *returnColumnSizes = malloc(intervalsSize * sizeof(int));

    *returnSize = 0;

    for (int i = 0; i < intervalsSize; i++)
    {
        int start = intervals[i][0];
        int end = intervals[i][1];

        // If there is an overlap with the previous interval
        if (*returnSize > 0 &&
            start <= result[*returnSize - 1][1])
        {
            if (end > result[*returnSize - 1][1])
                result[*returnSize - 1][1] = end;
        }
        else
        {
            result[*returnSize] = malloc(2 * sizeof(int));

            result[*returnSize][0] = start;
            result[*returnSize][1] = end;

            (*returnColumnSizes)[*returnSize] = 2;
            (*returnSize)++;
        }
    }

    return result;
}
