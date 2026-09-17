#include <stdbool.h>
#include <string.h>

bool isMatch(char* s, char* p)
{
    int m = strlen(s);
    int n = strlen(p);

    bool dp[m + 1][n + 1];

    dp[0][0] = true;

    // Empty string with pattern
    for (int j = 1; j <= n; j++)
    {
        if (p[j - 1] == '*')
            dp[0][j] = dp[0][j - 1];
        else
            dp[0][j] = false;
    }

    // Empty pattern with non-empty string
    for (int i = 1; i <= m; i++)
        dp[i][0] = false;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (p[j - 1] == '?' || p[j - 1] == s[i - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (p[j - 1] == '*')
            {
                // '*' matches empty OR one/more characters
                dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
            }
            else
            {
                dp[i][j] = false;
            }
        }
    }

    return dp[m][n];
}
