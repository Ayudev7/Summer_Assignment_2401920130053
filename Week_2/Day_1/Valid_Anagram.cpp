#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, int> freq;

        for (char c : s) freq[c]++;
        for (char c : t) freq[c]--;

        for (auto& p : freq) {
            if (p.second != 0) return false;
        }

        return true;
    }
};

int main() {
    Solution sol;

    string s, t;
    cout << "Enter first string:  ";
    cin >> s;
    cout << "Enter second string: ";
    cin >> t;

    bool result = sol.isAnagram(s, t);

    if (result)
        cout << "Anagram" << endl;
    else
        cout << "Not an Anagram" << endl;

    return 0;
}