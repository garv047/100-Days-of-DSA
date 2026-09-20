#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b)
{
    return (*(char*)a - *(char*)b);
}

char** sortString(char* s)
{
    char* temp = malloc((strlen(s) + 1) * sizeof(char));
    strcpy(temp, s);

    qsort(temp, strlen(temp), sizeof(char), compare);

    return &temp;
}

char*** groupAnagrams(char** strs, int strsSize,
                      int* returnSize, int** returnColumnSizes)
{
    char*** result = malloc(strsSize * sizeof(char**));
    *returnColumnSizes = malloc(strsSize * sizeof(int));

    char** keys = malloc(strsSize * sizeof(char*));
    int groupCount = 0;

    for (int i = 0; i < strsSize; i++)
    {
        char* key = malloc((strlen(strs[i]) + 1) * sizeof(char));
        strcpy(key, strs[i]);

        qsort(key, strlen(key), sizeof(char), compare);

        int group = -1;

        // Find an existing group
        for (int j = 0; j < groupCount; j++)
        {
            if (strcmp(keys[j], key) == 0)
            {
                group = j;
                break;
            }
        }

        // Create new group
        if (group == -1)
        {
            group = groupCount;
            keys[groupCount] = key;

            result[groupCount] = malloc(strsSize * sizeof(char*));
            (*returnColumnSizes)[groupCount] = 0;

            groupCount++;
        }
        else
        {
            free(key);
        }

        int pos = (*returnColumnSizes)[group];
        result[group][pos] = malloc((strlen(strs[i]) + 1) * sizeof(char));
        strcpy(result[group][pos], strs[i]);

        (*returnColumnSizes)[group]++;
    }

    *returnSize = groupCount;

    free(keys);

    return result;
}
