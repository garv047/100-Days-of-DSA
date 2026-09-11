int divide(int dividend, int divisor)
{
    // Overflow case
    if (dividend == -2147483648 && divisor == -1)
        return 2147483647;

    int negative = 0;

    if (dividend < 0)
        negative = !negative;

    if (divisor < 0)
        negative = !negative;

    long long a = dividend;
    long long b = divisor;

    if (a < 0)
        a = -a;

    if (b < 0)
        b = -b;

    long long quotient = 0;

    while (a >= b)
    {
        long long value = b;
        long long multiple = 1;

        // Find the largest multiple of divisor
        while ((value << 1) <= a)
        {
            value = value << 1;
            multiple = multiple << 1;
        }

        a = a - value;
        quotient = quotient + multiple;
    }

    if (negative)
        quotient = -quotient;

    if (quotient > 2147483647)
        return 2147483647;

    if (quotient < -2147483648LL)
        return -2147483648;

    return (int)quotient;
}
