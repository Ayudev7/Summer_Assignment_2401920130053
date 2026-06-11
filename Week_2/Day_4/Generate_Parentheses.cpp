#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> result;

    void solve(string current, int o, int c, int n) {
        if (current.size() == 2 * n) {
            result.push_back(current);
            return;
        }
        if (o < n) {
            solve(current + "(", o + 1, c, n);
        }
        if (c < o) {
            solve(current + ")", o, c + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        result.clear(); 
        solve("", 0, 0, n);
        return result;
    }
};

int main() {
    Solution sol;

    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<string> result = sol.generateParenthesis(n);

    cout << "Output (" << result.size() << " combinations):" << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << i + 1 << ". " << result[i] << endl;
    }

    return 0;
}