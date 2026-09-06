#include <stdlib.h>
#include <string.h>

char* letters[] = {
    "", "", "abc", "def", "ghi",
    "jkl", "mno", "pqrs", "tuv", "wxyz"
};

void backtrack(char* digits, int index, char* current,
               char** result, int* returnSize)
{
    if (digits[index] == '\0')
    {
        current[index] = '\0';

        result[*returnSize] = (char*)malloc((index + 1) * sizeof(char));
        strcpy(result[*returnSize], current);

        (*returnSize)++;
        return;
    }

    int digit = digits[index] - '0';
    int len = strlen(letters[digit]);

    for (int i = 0; i < len; i++)
    {
        current[index] = letters[digit][i];

        backtrack(digits, index + 1, current,
                  result, returnSize);
    }
}

char** letterCombinations(char* digits, int* returnSize)
{
    *returnSize = 0;

    if (digits[0] == '\0')
        return NULL;

    int n = strlen(digits);

    // Maximum possible combinations = 4^n
    int maxSize = 1;
    for (int i = 0; i < n; i++)
        maxSize *= 4;

    char** result = (char**)malloc(maxSize * sizeof(char*));
    char* current = (char*)malloc((n + 1) * sizeof(char));

    backtrack(digits, 0, current, result, returnSize);

    free(current);

    return result;
}
