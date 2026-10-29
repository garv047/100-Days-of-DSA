
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char **result;
int count;
char *parts[4];

void backtrack(char *s, int pos, int part) {
    int len = strlen(s);

    if (part == 4) {
        if (pos == len) {
            char ip[20] = "";
            for (int i = 0; i < 4; i++) {
                strcat(ip, parts[i]);
                if (i < 3) strcat(ip, ".");
            }

            result[count] = malloc(strlen(ip) + 1);
            strcpy(result[count++], ip);
        }
        return;
    }

    for (int l = 1; l <= 3 && pos + l <= len; l++) {
        char temp[4];
        strncpy(temp, s + pos, l);
        temp[l] = '\0';

        if (l > 1 && s[pos] == '0')
            break;

        int num = atoi(temp);
        if (num > 255)
            break;

        parts[part] = malloc(l + 1);
        strcpy(parts[part], temp);

        backtrack(s, pos + l, part + 1);

        free(parts[part]);
    }
}

char** restoreIpAddresses(char* s, int* returnSize) {
    result = malloc(1000 * sizeof(char *));
    count = 0;

    if (strlen(s) < 4 || strlen(s) > 12) {
        *returnSize = 0;
        return result;
    }

    backtrack(s, 0, 0);

    *returnSize = count;
    return result;
}
