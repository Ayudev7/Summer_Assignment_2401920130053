#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        int left = 0;
        int right = n - 1;
        int pos = n - 1; 

        while (left <= right) {
            int leftSq  = nums[left] * nums[left];
            int rightSq = nums[right] * nums[right];

            if (leftSq > rightSq) {
                result[pos] = leftSq;
                left++;
            } else {
                result[pos] = rightSq;
                right--;
            }
            pos--;
        }

        return result;
    }
};

int main() {
    Solution sol;

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> result = sol.sortedSquares(nums);

    cout << "Output: [";
    for (int i = 0; i < n; i++) {
        cout << result[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}