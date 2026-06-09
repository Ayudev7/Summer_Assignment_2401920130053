#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> seen;

        int left   = 0;
        int maxLen = 0;

        for (int right = 0; right < s.size(); right++) {
            if (seen.count(s[right]) && seen[s[right]] >= left) {
                left = seen[s[right]] + 1;
            }

            seen[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

int main() {
    Solution sol;

    string s;
    cout << "Enter string: ";
    cin >> s;

    int result = sol.lengthOfLongestSubstring(s);

    cout << "Length of Longest Substring: " << result << endl;

    return 0;
}