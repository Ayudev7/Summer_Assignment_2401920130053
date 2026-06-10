#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0; 
        int j = 0; 

        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }

        return i == s.size();
    }
};

int main() {
    Solution sol;

    string s, t;
    cout << "Enter s (pattern): ";
    cin >> s;
    cout << "Enter t (string):  ";
    cin >> t;

    bool result = sol.isSubsequence(s, t);

    if (result)
        cout << "is a subsequence" << endl;
    else
        cout << "not a subsequence" << endl;

    return 0;
}