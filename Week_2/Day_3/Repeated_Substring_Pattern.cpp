#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string doubled = s + s;
        string middle  = doubled.substr(1, doubled.size() - 2);
        return middle.find(s) != string::npos;
    }
};

int main() {
    Solution sol;

    string s;
    cout << "Enter string: ";
    cin >> s;

    bool result = sol.repeatedSubstringPattern(s);

    if (result)
        cout << "Output: true (is a repeated pattern)" << endl;
    else
        cout << "Output: false (not a repeated pattern)" << endl;

    return 0;
}