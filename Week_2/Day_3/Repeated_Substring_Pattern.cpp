#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();

        for (int len = 1; len <= n / 2; len++) {
            if (n % len == 0) {
                string sub = s.substr(0, len);
                string repeated = "";

                for (int i = 0; i < n / len; i++)
                    repeated += sub;

                if (repeated == s) return true;
            }
        }

        return false;
    }
};

int main() {
    Solution sol;

    string s;
    cout << "Enter string: ";
    cin >> s;

    bool result = sol.repeatedSubstringPattern(s);

    if (result)
        cout << "is a repeated pattern" << endl;
    else
        cout << "not a repeated pattern" << endl;

    return 0;
}