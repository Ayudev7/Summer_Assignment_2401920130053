#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> st;

        for (string& token : tokens) {
            if (token == "+" || token == "-" ||
                token == "*" || token == "/") {

                long b = st.top(); st.pop();
                long a = st.top(); st.pop();

                if      (token == "+") st.push(a + b);
                else if (token == "-") st.push(a - b);
                else if (token == "*") st.push(a * b);
                else if (token == "/") st.push(a / b);

            } else {
                st.push(stol(token));
            }
        }

        return st.top();
    }
};

int main() {
    Solution sol;

    int n;
    cout << "Enter number of tokens: ";
    cin >> n;

    vector<string> tokens(n);
    cout << "Enter tokens: ";
    for (int i = 0; i < n; i++)
        cin >> tokens[i];

    int result = sol.evalRPN(tokens);

    cout << "Output: " << result << endl;

    return 0;
}