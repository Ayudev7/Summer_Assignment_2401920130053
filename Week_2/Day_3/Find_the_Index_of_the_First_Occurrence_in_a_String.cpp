#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        if (m > n) return -1;

        for (int i = 0; i <= n - m; i++) {
            int j = 0;
            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }
            if (j == m) return i;
        }

        return -1;
    }
};

int main() {
    Solution sol;

    string haystack, needle;
    cout << "Enter haystack: ";
    cin >> haystack;
    cout << "Enter needle:   ";
    cin >> needle;

    int result = sol.strStr(haystack, needle);

    if (result == -1)
        cout << "Output: -1 (not found)" << endl;
    else
        cout << "Output: " << result
             << " (found at index " << result << ")" << endl;

    return 0;
}