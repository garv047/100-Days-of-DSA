
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    int *x = *(int **)a;
    int *y = *(int **)b;

    return x[0] - y[0];
}

int maxBuilding(int n, int** restrictions, int restrictionsSize,
                int* restrictionsColSize) {

    int size = restrictionsSize + 1;

    int **arr = malloc((size + 1) * sizeof(int *));

    // Add first building restriction
    for (int i = 0; i < size + 1; i++)
        arr[i] = malloc(2 * sizeof(int));

    arr[0][0] = 1;
    arr[0][1] = 0;

    for (int i = 0; i < restrictionsSize; i++) {
        arr[i + 1][0] = restrictions[i][0];
        arr[i + 1][1] = restrictions[i][1];
    }

    // Add last building restriction if not already present
    if (restrictionsSize == 0 ||
        arr[restrictionsSize][0] != n) {
        arr[size][0] = n;
        arr[size][1] = n - 1;
        size++;
    }

    qsort(arr, size, sizeof(int *), cmp);

    // Forward pass
    for (int i = 1; i < size; i++) {
        int diff = arr[i][0] - arr[i - 1][0];

        if (arr[i][1] > arr[i - 1][1] + diff)
            arr[i][1] = arr[i - 1][1] + diff;
    }

    // Backward pass
    for (int i = size - 2; i >= 0; i--) {
        int diff = arr[i + 1][0] - arr[i][0];

        if (arr[i][1] > arr[i + 1][1] + diff)
            arr[i][1] = arr[i + 1][1] + diff;
    }

    int ans = 0;

    // Find maximum possible peak
    for (int i = 1; i < size; i++) {
        long long diff = arr[i][0] - arr[i - 1][0];

        long long height =
            ((long long)arr[i - 1][1] +
             arr[i][1] + diff) / 2;

        if (height > ans)
            ans = height;
    }

    for (int i = 0; i < size; i++)
        free(arr[i]);

    free(arr);

    return ans;
}
