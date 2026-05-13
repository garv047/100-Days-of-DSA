#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ── Fenwick (Binary Indexed) Tree ── */
static int bit[20001];
static int bit_n;

static void bit_update(int i, int delta) {
    for (; i <= bit_n; i += i & (-i))
        bit[i] += delta;
}

static int bit_query(int i) {
    int s = 0;
    for (; i > 0; i -= i & (-i))
        s += bit[i];
    return s;
}

/* ── Comparator for qsort (ascending) ── */
static int cmp_int(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

/* ── Coordinate compression: map nums → ranks 1..n ── */
static int compress(int val, const int *sorted, int n) {
    int lo = 0, hi = n - 1;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (sorted[mid] < val) lo = mid + 1;
        else                   hi = mid;
    }
    return lo + 1;          /* 1-indexed rank */
}

/* ── Main solver ── */
int *countSmaller(int *nums, int numsSize, int *returnSize) {
    *returnSize = numsSize;
    int *result = (int *)calloc(numsSize, sizeof(int));
    if (numsSize == 0) return result;

    /* 1. Coordinate compress */
    int *sorted = (int *)malloc(numsSize * sizeof(int));
    memcpy(sorted, nums, numsSize * sizeof(int));
    qsort(sorted, numsSize, sizeof(int), cmp_int);

    /* Remove duplicates */
    int unique = 0;
    for (int i = 0; i < numsSize; i++)
        if (i == 0 || sorted[i] != sorted[i - 1])
            sorted[unique++] = sorted[i];

    bit_n = unique;
    memset(bit, 0, (bit_n + 1) * sizeof(int));

    /* 2. Sweep right → left */
    for (int i = numsSize - 1; i >= 0; i--) {
        int rank = compress(nums[i], sorted, unique);
        result[i] = bit_query(rank - 1);   /* count elements with rank < current */
        bit_update(rank, 1);               /* mark this element as seen           */
    }

    free(sorted);
    return result;
}

/* ── Driver ── */
int main(void) {
    int nums[] = {5, 2, 6, 1};
    int n = 4, retSize;
    int *ans = countSmaller(nums, n, &retSize);

    printf("Input:  ");
    for (int i = 0; i < n; i++) printf("%d ", nums[i]);
    printf("\nOutput: ");
    for (int i = 0; i < n; i++) printf("%d ", ans[i]);
    printf("\n");          /* Expected: 2 1 1 0 */

    free(ans);
    return 0;
}
