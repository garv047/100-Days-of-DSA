
int countPoints(char* rings) {
    int a[10][3] = {0};
    int count = 0;

    for (int i = 0; rings[i] != '\0'; i += 2) {
        int rod = rings[i + 1] - '0';

        if (rings[i] == 'R')
            a[rod][0] = 1;
        else if (rings[i] == 'G')
            a[rod][1] = 1;
        else if (rings[i] == 'B')
            a[rod][2] = 1;
    }

    for (int i = 0; i < 10; i++) {
        if (a[i][0] && a[i][1] && a[i][2])
            count++;
    }

    return count;
}
