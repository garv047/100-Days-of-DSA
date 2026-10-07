#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    int* result = malloc((digitsSize + 1) * sizeof(int));

    for (int i = digitsSize - 1; i >= 0; i--)
    {
        if (digits[i] < 9)
        {
            digits[i]++;
            *returnSize = digitsSize;
            return digits;
        }

        digits[i] = 0;
    }

    // If all digits were 9
    result[0] = 1;

    for (int i = 1; i <= digitsSize; i++)
        result[i] = 0;

    *returnSize = digitsSize + 1;

    return result;
}
