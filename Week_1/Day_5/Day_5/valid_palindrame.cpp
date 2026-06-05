#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left  = 0;
        int right = s.length() - 1;

        while (left < right) {
            if (!isalnum(s[left])) {
                left++;
                continue;
            }
            if (!isalnum(s[right])) {
                right--;
                continue;
            }
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

int main() {
    Solution sol;

    string s;
    cout << "Enter string: ";
    getline(cin, s);

    bool result = sol.isPalindrome(s);

    if (result)
        cout << "Output: true (Palindrome)" << endl;
    else
        cout << "Output: false (Not a Palindrome)" << endl;

    return 0;
}