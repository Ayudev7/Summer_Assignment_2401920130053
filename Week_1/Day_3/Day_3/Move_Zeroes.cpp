#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0; // position to place next non-zero

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
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

    cout << "Before: [";
    for (int i = 0; i < n; i++) {
        cout << nums[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;

    sol.moveZeroes(nums);

    cout << "After:  [";
    for (int i = 0; i < n; i++) {
        cout << nums[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}


