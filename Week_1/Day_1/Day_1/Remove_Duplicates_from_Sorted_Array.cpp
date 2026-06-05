#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int i = 0; 

        for (int j = 1; j < n; j++) {
            if (nums[i] != nums[j]) {
                i++;
                nums[i] = nums[j];
               
            }
        }

        return i+1;
    }
};

int main() {
    Solution sol;

    int n;
    cout << "enter the number of element";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " sorted element";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k = sol.removeDuplicates(nums);

    cout << "Number of unique elements: " << k << endl;
    cout << "Array after removing duplicates: [";
    for (int i = 0; i < k; i++) {
        cout << nums[i];
        if (i < k - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}

