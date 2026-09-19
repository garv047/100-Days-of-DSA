#include <stdlib.h>

void backtrack(int* nums, int numsSize, int* current, int currentSize,
               int* used, int** result, int* returnSize)
{
    if (currentSize == numsSize)
    {
        result[*returnSize] = malloc(numsSize * sizeof(int));

        for (int i = 0; i < numsSize; i++)
            result[*returnSize][i] = current[i];

        (*returnSize)++;
        return;
    }

    for (int i = 0; i < numsSize; i++)
    {
        if (used[i] == 1)
            continue;

        used[i] = 1;
        current[currentSize] = nums[i];

        backtrack(nums, numsSize, current, currentSize + 1,
                  used, result, returnSize);

        used[i] = 0;
    }
}

int** permute(int* nums, int numsSize, int* returnSize,
              int** returnColumnSizes)
{
    int total = 1;

    for (int i = 1; i <= numsSize; i++)
        total *= i;

    int** result = malloc(total * sizeof(int*));
    *returnColumnSizes = malloc(total * sizeof(int));
    int* current = malloc(numsSize * sizeof(int));
    int* used = calloc(numsSize, sizeof(int));

    *returnSize = 0;

    backtrack(nums, numsSize, current, 0,
              used, result, returnSize);

    for (int i = 0; i < *returnSize; i++)
        (*returnColumnSizes)[i] = numsSize;

    free(current);
    free(used);

    return result;
}
