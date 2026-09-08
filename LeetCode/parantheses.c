#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isValid(char* s)
{
    int n = strlen(s);
    char* stack = (char*)malloc(n * sizeof(char));
    int top = -1;

    for (int i = 0; i < n; i++)
    {
        // Opening brackets
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            stack[++top] = s[i];
        }
        // Closing brackets
        else
        {
            if (top == -1)
            {
                free(stack);
                return false;
            }

            char open = stack[top--];

            if ((s[i] == ')' && open != '(') ||
                (s[i] == '}' && open != '{') ||
                (s[i] == ']' && open != '[')
               )
            {
                free(stack);
                return false;
            }
        }
    }

    bool result = (top == -1);

    free(stack);
    return result;
}
