
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* digitSum(char* s, int k) {
    int len = strlen(s);

    while (len > k) {
        char *result = malloc(len * 3 + 1);
        int pos = 0;

        for (int i = 0; i < len; i += k) {
            int sum = 0;

            for (int j = i; j < i + k && j < len; j++) {
                sum += s[j] - '0';
            }

            pos += sprintf(result + pos, "%d", sum);
        }

        result[pos] = '\0';

        free(s);
        s = result;
        len = strlen(s);
    }

    return s;
}
