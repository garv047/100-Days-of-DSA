
class Solution {
public:
    unordered_map<string, bool> memo;

    bool solve(string a, string b) {
        if (a == b) return true;

        if (a.size() != b.size()) return false;

        string key = a + "#" + b;
        if (memo.count(key)) return memo[key];

        int n = a.size();

        // Check whether both strings have the same characters
        string x = a, y = b;
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        if (x != y) return memo[key] = false;

        for (int i = 1; i < n; i++) {
            // No swap
            if (solve(a.substr(0, i), b.substr(0, i)) &&
                solve(a.substr(i), b.substr(i))) {
                return memo[key] = true;
            }

            // Swap
            if (solve(a.substr(0, i), b.substr(n - i)) &&
                solve(a.substr(i), b.substr(0, n - i))) {
                return memo[key] = true;
            }
        }

        return memo[key] = false;
    }

    bool isScramble(string s1, string s2) {
        return solve(s1, s2);
    }
};
