
#include <stdlib.h>
#include <string.h>

char* simplifyPath(char* path) {
    char *stack[3000];
    int top = 0;

    char *token = strtok(path, "/");

    while (token != NULL) {
        if (strcmp(token, ".") == 0) {
            // Ignore current directory
        }
        else if (strcmp(token, "..") == 0) {
            if (top > 0)
                top--;
        }
        else {
            stack[top++] = token;
        }

        token = strtok(NULL, "/");
    }

    char *result = malloc(3005);
    int pos = 0;

    result[pos++] = '/';

    for (int i = 0; i < top; i++) {
        int len = strlen(stack[i]);
        memcpy(result + pos, stack[i], len);
        pos += len;

        if (i < top - 1)
            result[pos++] = '/';
    }

    result[pos] = '\0';
    return result;
}
