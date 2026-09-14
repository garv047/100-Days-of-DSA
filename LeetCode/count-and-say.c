#include <stdlib.h>
#include <string.h>

char* countAndSay(int n)
{
    char* current = (char*)malloc(5000 * sizeof(char));
    char* next = (char*)malloc(5000 * sizeof(char));

    strcpy(current, "1");

    for (int k = 2; k <= n; k++)
    {
        int i = 0;
        int index = 0;

        while (current[i] != '\0')
        {
            char digit = current[i];
            int count = 0;

            // Count consecutive same digits
            while (current[i] == digit)
            {
                count++;
                i++;
            }

            // Add count
            if (count == 1)
                next[index++] = '1';
            else if (count == 2)
                next[index++] = '2';
            else if (count == 3)
                next[index++] = '3';
            else if (count == 4)
                next[index++] = '4';

            // Add digit
            next[index++] = digit;
        }

        next[index] = '\0';

        strcpy(current, next);
    }

    free(next);

    return current;
}
