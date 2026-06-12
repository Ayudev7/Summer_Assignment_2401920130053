#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int write = 0; 
        int i     = 0; 

        while (i < chars.size()) {
            char ch    = chars[i];
            int  count = 0;

            // count consecutive same characters
            while (i < chars.size() && chars[i] == ch) {
                i++;
                count++;
            }

            
            chars[write++] = ch;

           
            if (count > 1) {
                string cnt = to_string(count);
                for (unsigned char c : cnt)
                    chars[write++] = c;
            }
        }

        return write;
    }
};

int main() {
    Solution sol;

    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    vector<char> chars(n);
    cout << "Enter " << n << " characters: ";
    for (int i = 0; i < n; i++)
        cin >> chars[i];

    cout << "Before: [";
    for (int i = 0; i < n; i++) {
        cout << chars[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;

    int len = sol.compress(chars);

    cout << "After:  [";
    for (int i = 0; i < len; i++) {
        cout << chars[i];
        if (i < len - 1) cout << ", ";
    }
    cout << "]" << endl;
    cout << "Length: " << len << endl;

    return 0;
}