
#include <stdlib.h>
#include <string.h>

char** fullJustify(char** words, int wordsSize, int maxWidth,
                   int* returnSize) {
    char** result = malloc(wordsSize * sizeof(char*));
    int count = 0;
    int i = 0;

    while (i < wordsSize) {
        int j = i;
        int len = 0;

        // Pack as many words as possible
        while (j < wordsSize &&
               len + strlen(words[j]) + (j - i) <= maxWidth) {
            len += strlen(words[j]);
            j++;
        }

        int numWords = j - i;
        int spaces = maxWidth - len;

        char* line = malloc((maxWidth + 1) * sizeof(char));
        int pos = 0;

        // Last line or line with only one word
        if (j == wordsSize || numWords == 1) {
            for (int k = i; k < j; k++) {
                int l = strlen(words[k]);
                memcpy(line + pos, words[k], l);
                pos += l;

                if (k < j - 1) {
                    line[pos++] = ' ';
                    spaces--;
                }
            }

            while (pos < maxWidth) {
                line[pos++] = ' ';
            }
        } else {
            int gaps = numWords - 1;
            int each = spaces / gaps;
            int extra = spaces % gaps;

            for (int k = i; k < j; k++) {
                int l = strlen(words[k]);
                memcpy(line + pos, words[k], l);
                pos += l;

                if (k < j - 1) {
                    int add = each + (extra > 0 ? 1 : 0);

                    for (int s = 0; s < add; s++) {
                        line[pos++] = ' ';
                    }

                    if (extra > 0) extra--;
                }
            }
        }

        line[maxWidth] = '\0';
        result[count++] = line;
        i = j;
    }

    *returnSize = count;
    return result;
}
