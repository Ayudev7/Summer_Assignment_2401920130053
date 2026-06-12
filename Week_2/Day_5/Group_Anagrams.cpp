#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string& s : strs) {
            int freq[26] = {0};
            for (unsigned char c : s)
                freq[c - 'a']++;

            string key = "";
            for (int i = 0; i < 26; i++)
                key += to_string(freq[i]) + "#";

            mp[key].push_back(s);
        }

        vector<vector<string>> result;
        for (auto& pair : mp)
            result.push_back(pair.second);

        return result;
    }
};

int main() {
    Solution sol;

    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    vector<string> strs(n);
    cout << "Enter " << n << " strings:" << endl;
    for (int i = 0; i < n; i++)
        cin >> strs[i];

    vector<vector<string>> result = sol.groupAnagrams(strs);

    cout << "Output:" << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << "Group " << i + 1 << ": [";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if (j < result[i].size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}