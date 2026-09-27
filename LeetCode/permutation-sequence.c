#include <stdlib.h>

char* getPermutation(int n, int k)
{
    char* result = malloc((n + 1) * sizeof(char));
    int numbers[10];

    // Store 1, 2, 3, ..., n
    for (int i = 0; i < n; i++)
        numbers[i] = i + 1;

    // Calculate (n-1)!
    int fact = 1;
    for (int i = 1; i < n; i++)
        fact *= i;

    // Make k zero-based
    k--;

    for (int i = 0; i < n; i++)
    {
        int index = k / fact;

        result[i] = numbers[index] + '0';

        // Remove selected number
        for (int j = index; j < n - i - 1; j++)
            numbers[j] = numbers[j + 1];

        k = k % fact;

        if (n - i - 1 > 0)
            fact = fact / (n - i - 1);
    }

    result[n] = '\0';

    return result;
}
