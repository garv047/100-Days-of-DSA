
#include <stdlib.h>
#include <string.h>

char* addBinary(char* a, char* b) {
    int i = strlen(a) - 1;
    int j = strlen(b) - 1;
    int carry = 0;

    int max = (i > j ? i : j) + 2;
    char* result = (char*)malloc(max + 1);
    int k = 0;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;

        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';

        result[k++] = (sum % 2) + '0';
        carry = sum / 2;
    }

    result[k] = '\0';

    // Reverse the result
    for (int x = 0; x < k / 2; x++) {
        char temp = result[x];
        result[x] = result[k - 1 - x];
        result[k - 1 - x] = temp;
    }

    return result;
}
