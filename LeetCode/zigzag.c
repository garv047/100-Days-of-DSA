char* convert(char* s, int numRows)
{
    static char result[10000];
    int len = 0;
    int index = 0;

    while (s[len] != '\0')
        len++;

    if (numRows == 1 || numRows >= len)
        return s;

    int cycle = 2 * numRows - 2;

    for (int row = 0; row < numRows; row++)
    {
        for (int i = row; i < len; i += cycle)
        {
            result[index++] = s[i];

            // Middle rows have an extra character
            int diagonal = i + cycle - 2 * row;

            if (row != 0 && row != numRows - 1 && diagonal < len)
            {
                result[index++] = s[diagonal];
            }
        }
    }

    result[index] = '\0';

    return result;
}
