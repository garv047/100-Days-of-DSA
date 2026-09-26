#include <stdlib.h>

int** insert(int** intervals, int intervalsSize,
             int* intervalsColSize, int* newInterval,
             int newIntervalSize, int* returnSize,
             int** returnColumnSizes)
{
    int** result = malloc((intervalsSize + 1) * sizeof(int*));
    *returnColumnSizes = malloc((intervalsSize + 1) * sizeof(int));

    *returnSize = 0;

    int start = newInterval[0];
    int end = newInterval[1];

    int i = 0;

    // 1. Intervals before newInterval
    while (i < intervalsSize && intervals[i][1] < start)
    {
        result[*returnSize] = malloc(2 * sizeof(int));

        result[*returnSize][0] = intervals[i][0];
        result[*returnSize][1] = intervals[i][1];

        (*returnColumnSizes)[*returnSize] = 2;
        (*returnSize)++;

        i++;
    }

    // 2. Merge overlapping intervals
    while (i < intervalsSize && intervals[i][0] <= end)
    {
        if (intervals[i][0] < start)
            start = intervals[i][0];

        if (intervals[i][1] > end)
            end = intervals[i][1];

        i++;
    }

    // Add merged interval
    result[*returnSize] = malloc(2 * sizeof(int));
    result[*returnSize][0] = start;
    result[*returnSize][1] = end;

    (*returnColumnSizes)[*returnSize] = 2;
    (*returnSize)++;

    // 3. Intervals after newInterval
    while (i < intervalsSize)
    {
        result[*returnSize] = malloc(2 * sizeof(int));

        result[*returnSize][0] = intervals[i][0];
        result[*returnSize][1] = intervals[i][1];

        (*returnColumnSizes)[*returnSize] = 2;
        (*returnSize)++;

        i++;
    }

    return result;
}
