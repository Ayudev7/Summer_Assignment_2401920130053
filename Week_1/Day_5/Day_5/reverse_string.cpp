#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left  = 0;
        int right = s.size() - 1;

        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};

int main() {
    Solution sol;

    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    vector<char> s(n);
    cout << "Enter " << n << " characters: ";
    for (int i = 0; i < n; i++)
        cin >> s[i];

    cout << "Before: [";
    for (int i = 0; i < n; i++) {
        cout << s[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;

    sol.reverseString(s);

    cout << "After:  [";
    for (int i = 0; i < n; i++) {
        cout << s[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}