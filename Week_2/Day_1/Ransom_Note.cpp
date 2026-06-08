#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int freq[26] = {0};

        for (char c : magazine)
            freq[c - 'a']++;

        for (char c : ransomNote) {
            freq[c - 'a']--;
            if (freq[c - 'a'] < 0)
                return false;
        }

        return true;
    }
};

int main() {
    Solution sol;

    string ransomNote, magazine;
    cout << "Enter ransom note: ";
    cin >> ransomNote;
    cout << "Enter magazine:    ";
    cin >> magazine;

    bool result = sol.canConstruct(ransomNote, magazine);

    if (result)
        cout << "Output: true (can construct)" << endl;
    else
        cout << "Output: false (cannot construct)" << endl;

    return 0;
}