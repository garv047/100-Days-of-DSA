#include <stdbool.h>

bool isNumber(char* s)
{
    int i = 0;
    bool digitSeen = false;
    bool dotSeen = false;
    bool exponentSeen = false;
    bool digitAfterExponent = true;

    while (s[i] != '\0')
    {
        char c = s[i];

        // Digit
        if (c >= '0' && c <= '9')
        {
            digitSeen = true;

            if (exponentSeen)
                digitAfterExponent = true;
        }

        // Decimal point
        else if (c == '.')
        {
            if (dotSeen || exponentSeen)
                return false;

            dotSeen = true;
        }

        // Exponent
        else if (c == 'e' || c == 'E')
        {
            if (exponentSeen || !digitSeen)
                return false;

            exponentSeen = true;
            digitAfterExponent = false;
        }

        // Sign
        else if (c == '+' || c == '-')
        {
            if (i != 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                return false;
        }

        // Anything else is invalid
        else
        {
            return false;
        }

        i++;
    }

    return digitSeen && digitAfterExponent;
}
