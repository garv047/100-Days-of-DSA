
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        vector<int> freq(128, 0);

        for (char c : t) {
            freq[c]++;
        }

        int left = 0;
        int required = t.size();
        int minLen = s.size() + 1;
        int start = 0;

        for (int right = 0; right < s.size(); right++) {
            if (freq[s[right]] > 0) {
                required--;
            }
            freq[s[right]]--;

            while (required == 0) {
                int len = right - left + 1;

                if (len < minLen) {
                    minLen = len;
                    start = left;
                }

                freq[s[left]]++;

                if (freq[s[left]] > 0) {
                    required++;
                }

                left++;
            }
        }

        return minLen == s.size() + 1
                   ? ""
                   : s.substr(start, minLen);
    }
};

int main() {
    Solution sol;

    string s = "ADOBECODEBANC";
    string t = "ABC";

    cout << sol.minWindow(s, t) << endl;

    return 0;
}
