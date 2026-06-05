#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;

        
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        double maxsum = sum;

        
        for (int i = k; i < nums.size(); i++) {
            sum += nums[i] - nums[i - k]; 
            maxsum = max(maxsum, sum);
        }

        return maxsum/k;
    }
};

int main() {
    Solution sol;

    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter window size k: ";
    cin >> k;

    double result = sol.findMaxAverage(nums, k);

    // cout << fixed << setprecision(5);
    cout << "Maximum Average: " << result << endl;

    return 0;
}