#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> st; 

        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
                int idx      = st.top();
                st.pop();
                result[idx]  = i - idx;
            }
            st.push(i);
        }

        return result;
    }
};

int main() {
    Solution sol;

    int n;
    cout << "Enter number of days: ";
    cin >> n;

    vector<int> temperatures(n);
    cout << "Enter temperatures: ";
    for (int i = 0; i < n; i++)
        cin >> temperatures[i];

    vector<int> result = sol.dailyTemperatures(temperatures);

    cout << "Output: [";
    for (int i = 0; i < n; i++) {
        cout << result[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}