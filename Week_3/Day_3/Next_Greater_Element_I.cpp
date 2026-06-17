#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        stack<int> st;

        for (int i = 0; i < nums2.size(); i++) {
            while (!st.empty() && st.top() < nums2[i]) {
                nextGreater[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }

        vector<int> result;
        for (int i = 0; i < nums1.size(); i++) {
            if (nextGreater.count(nums1[i]))
                result.push_back(nextGreater[nums1[i]]);
            else
                result.push_back(-1);
        }

        return result;
    }
};

int main() {
    Solution sol;

    int n, m;
    cout << "Enter size of nums1: ";
    cin >> n;
    vector<int> nums1(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> nums1[i];

    cout << "Enter size of nums2: ";
    cin >> m;
    vector<int> nums2(m);
    cout << "Enter " << m << " elements: ";
    for (int i = 0; i < m; i++) cin >> nums2[i];

    vector<int> result = sol.nextGreaterElement(nums1, nums2);

    cout << "Output: [";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}