#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        int freq1[26] = {0};
        int freq2[26] = {0};

        for (int i = 0; i < s1.size(); i++) {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }

      
        if (equal(freq1, freq1 + 26, freq2)) return true;

        for (int i = s1.size(); i < s2.size(); i++) {
            freq2[s2[i] - 'a']++;
            freq2[s2[i - s1.size()] - 'a']--;

           
            if (equal(freq1, freq1 + 26, freq2)) return true;
        }

        return false;
    }
};

int main() {
    Solution sol;

    string s1, s2;
    cout << "Enter s1 (pattern): ";
    cin >> s1;
    cout << "Enter s2 (string):  ";
    cin >> s2;

    bool result = sol.checkInclusion(s1, s2);

    if (result)
        cout << "Output: true (permutation found)" << endl;
    else
        cout << "Output: false (no permutation found)" << endl;

    return 0;
}