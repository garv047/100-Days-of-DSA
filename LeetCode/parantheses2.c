#include <stdlib.h>
#include <string.h>

void generate(char** result, int* returnSize, char* current,
              int pos, int open, int close, int n)
{
    if (pos == 2 * n)
    {
        current[pos] = '\0';

        result[*returnSize] = (char*)malloc((2 * n + 1) * sizeof(char));
        strcpy(result[*returnSize], current);

        (*returnSize)++;
        return;
    }

    // Add opening bracket
    if (open < n)
    {
        current[pos] = '(';
        generate(result, returnSize, current,
                 pos + 1, open + 1, close, n);
    }

    // Add closing bracket only if there is an unmatched '('
    if (close < open)
    {
        current[pos] = ')';
        generate(result, returnSize, current,
                 pos + 1, open, close + 1, n);
    }
}

char** generateParenthesis(int n, int* returnSize)
{
    *returnSize = 0;

    int maxSize = 1;

    for (int i = 0; i < 2 * n; i++)
        maxSize *= 2;

    char** result = (char**)malloc(maxSize * sizeof(char*));
    char* current = (char*)malloc((2 * n + 1) * sizeof(char));

    generate(result, returnSize, current, 0, 0, 0, n);

    free(current);

    return result;
}
