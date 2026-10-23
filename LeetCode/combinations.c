
#include <stdlib.h>

int count;
int **result;
int *columnSizes;
int *path;
int nVal, kVal;

void backtrack(int start, int depth) {
    if (depth == kVal) {
        result[count] = (int *)malloc(kVal * sizeof(int));

        for (int i = 0; i < kVal; i++) {
            result[count][i] = path[i];
        }

        columnSizes[count] = kVal;
        count++;
        return;
    }

    for (int i = start; i <= nVal - (kVal - depth) + 1; i++) {
        path[depth] = i;
        backtrack(i + 1, depth + 1);
    }
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes) {
    count = 0;
    nVal = n;
    kVal = k;

    int total = 1;
    for (int i = 0; i < k; i++) {
        total = total * (n - i) / (i + 1);
    }

    result = (int **)malloc(total * sizeof(int *));
    columnSizes = (int *)malloc(total * sizeof(int));
    path = (int *)malloc(k * sizeof(int));

    backtrack(1, 0);

    *returnSize = count;
    *returnColumnSizes = columnSizes;

    free(path);

    return result;
}
