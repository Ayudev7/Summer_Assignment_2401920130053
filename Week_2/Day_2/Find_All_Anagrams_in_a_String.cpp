#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;

        if (p.size() > s.size()) return result;

        int freqP[26] = {0};
        int freqS[26] = {0};

        
        for (int i = 0; i < p.size(); i++) {
            freqP[p[i] - 'a']++;
            freqS[s[i] - 'a']++;
        }

        if (equal(freqP, freqP + 26, freqS))
            result.push_back(0);

    
        for (int i = p.size(); i < s.size(); i++) {
            freqS[s[i] - 'a']++;                   
            freqS[s[i - p.size()] - 'a']--;        
            if (equal(freqP, freqP + 26, freqS))
                result.push_back(i - p.size() + 1); 
        }

        return result;
    }
};

int main() {
    Solution sol;

    string s, p;
    cout << "Enter string s: ";
    cin >> s;
    cout << "Enter pattern p: ";
    cin >> p;

    vector<int> result = sol.findAnagrams(s, p);

    if (result.empty()) {
        cout << "no anagrams found" << endl;
    } else {
        cout << "Output: [";
        for (int i = 0; i < result.size(); i++) {
            cout << result[i];
            if (i < result.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}