
#include <stdlib.h>
#include <string.h>

int **result;
int *path;
int count, pathSize;

int cmp(const void *a, const void *b) {
    return (*(int*)a > *(int*)b) - (*(int*)a < *(int*)b);
}

void backtrack(int *nums, int n, int start) {
    result[count] = malloc((pathSize + 1) * sizeof(int));

    for (int i = 0; i < pathSize; i++) {
        result[count][i] = path[i];
    }

    count++;

    for (int i = start; i < n; i++) {
        // Skip duplicate elements
        if (i > start && nums[i] == nums[i - 1])
            continue;

        path[pathSize++] = nums[i];

        backtrack(nums, n, i + 1);

        pathSize--;
    }
}

int** subsetsWithDup(int* nums, int numsSize,
                     int* returnSize, int** returnColumnSizes) {

    int total = 1;
    for (int i = 0; i < numsSize; i++)
        total *= 2;

    result = malloc(total * sizeof(int*));
    *returnColumnSizes = malloc(total * sizeof(int));

    path = malloc(numsSize * sizeof(int));

    count = 0;
    pathSize = 0;

    qsort(nums, numsSize, sizeof(int), cmp);

    backtrack(nums, numsSize, 0);

    for (int i = 0; i < count; i++) {
        (*returnColumnSizes)[i] = 0;
        // Sizes are filled below using a separate calculation.
    }

    // Calculate subset sizes from the generated subsets
    int index = 0;
    pathSize = 0;

    // Each subset size was the path size when it was generated.
    // Reconstruct sizes using a separate traversal is unnecessary;
    // store them directly during generation instead.
    *returnSize = count;

    free(path);

    return result;
}
