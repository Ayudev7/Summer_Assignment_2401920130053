#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> M;

        for (int i = 0; i < nums.size(); i++) {
            if (M.count(nums[i])) {
                return true;
            }
            M.insert(nums[i]);
        }

        return false;
    }
};

int main() {
    Solution sol;

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    bool result = sol.containsDuplicate(nums);

    if (result) {
        cout << "duplicate found" << endl;
    } else {
        cout << "no duplicates" << endl;
    }

    return 0;
}