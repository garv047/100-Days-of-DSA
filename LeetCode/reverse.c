int reverse(int x)
{
    int rev = 0;
    int digit;

    while (x != 0)
    {
        digit = x % 10;
        x = x / 10;

        // Check positive overflow
        if (rev > 214748364 || 
            (rev == 214748364 && digit > 7))
        {
            return 0;
        }

        // Check negative overflow
        if (rev < -214748364 || 
            (rev == -214748364 && digit < -8))
        {
            return 0;
        }

        rev = rev * 10 + digit;
    }

    return rev;
}
