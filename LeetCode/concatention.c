#include <stdlib.h>
#include <string.h>

int* findSubstring(char* s, char** words, int wordsSize, int* returnSize)
{
    int n = strlen(s);
    int len = strlen(words[0]);
    int total = len * wordsSize;

    int* result = malloc(n * sizeof(int));
    *returnSize = 0;

    for (int i = 0; i <= n - total; i++)
    {
        int count = 0;
        int used[wordsSize];

        for (int j = 0; j < wordsSize; j++)
            used[j] = 0;

        for (int j = 0; j < wordsSize; j++)
        {
            char temp[21];

            strncpy(temp, s + i + j * len, len);
            temp[len] = '\0';

            for (int k = 0; k < wordsSize; k++)
            {
                if (!used[k] && strcmp(temp, words[k]) == 0)
                {
                    used[k] = 1;
                    count++;
                    break;
                }
            }
        }

        if (count == wordsSize)
            result[(*returnSize)++] = i;
    }

    return result;
}
