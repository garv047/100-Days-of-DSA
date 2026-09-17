#include <stdlib.h>
#include <string.h>

char* multiply(char* num1, char* num2)
{
    int n = strlen(num1);
    int m = strlen(num2);

    int* result = (int*)calloc(n + m, sizeof(int));

    // Multiply digit by digit
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            int a = num1[i] - '0';
            int b = num2[j] - '0';

            result[i + j + 1] += a * b;
        }
    }

    // Handle carry
    for (int i = n + m - 1; i > 0; i--)
    {
        result[i - 1] += result[i] / 10;
        result[i] %= 10;
    }

    // Skip leading zeros
    int start = 0;

    while (start < n + m - 1 && result[start] == 0)
        start++;

    char* answer = (char*)malloc((n + m - start + 1) * sizeof(char));

    int k = 0;

    for (int i = start; i < n + m; i++)
        answer[k++] = result[i] + '0';

    answer[k] = '\0';

    free(result);

    return answer;
}
