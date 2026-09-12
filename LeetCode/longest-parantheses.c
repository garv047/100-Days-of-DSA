#include <stdlib.h>
#include <string.h>

int longestValidParentheses(char* s)
{
    int n = strlen(s);
    int* stack = (int*)malloc((n + 1) * sizeof(int));

    int top = 0;
    stack[0] = -1;

    int maxLength = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            stack[++top] = i;
        }
        else
        {
            top--;

            if (top < 0)
            {
                stack[++top] = i;
            }
            else
            {
                int length = i - stack[top];

                if (length > maxLength)
                    maxLength = length;
            }
        }
    }

    free(stack);

    return maxLength;
}
