#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26] = {0};

        for (char c : s)
            freq[c - 'a']++;

        for (int i = 0; i < s.size(); i++)
            if (freq[s[i] - 'a'] == 1)
                return i;

        return -1;
    }
};

int main() {
    Solution sol;

    string s;
    cout << "Enter string: ";
    cin >> s;

    int result = sol.firstUniqChar(s);

    if (result == -1)
        cout << "Output: -1 (no unique character)" << endl;
    else
        cout << "Output: " << result
             << " (first unique char is '"
             << s[result] << "')" << endl;

    return 0;
}