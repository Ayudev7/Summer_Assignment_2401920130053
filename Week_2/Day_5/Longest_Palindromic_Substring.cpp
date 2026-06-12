#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string expandAroundCenter(string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }

    string longestPalindrome(string s) {
        string result = "";

        for (int i = 0; i < s.size(); i++) {
            
            string odd  = expandAroundCenter(s, i, i);

            
            string even = expandAroundCenter(s, i, i + 1);

            if (odd.size()  > result.size()) result = odd;
            if (even.size() > result.size()) result = even;
        }

        return result;
    }
};

int main() {
    Solution sol;

    string s;
    cout << "Enter string: ";
    cin >> s;

    string result = sol.longestPalindrome(s);

    cout << "Output: " << result << endl;
    cout << "Length: " << result.size() << endl;

    return 0;
}