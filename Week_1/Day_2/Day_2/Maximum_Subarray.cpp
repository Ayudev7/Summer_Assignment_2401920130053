
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       
        int max = INT_MIN;
        int sum = 0;

        for(int i = 0; i < nums.size(); i++) {
            sum = sum + nums[i];
            if(sum>max){
                max =sum;
            }
            if(sum<0){
                sum =0;
               
            }
            
           
        }

        return max;
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

    int result = sol.maxSubArray(nums);

    cout << "Maximum Subarray Sum: " << result << endl;

    return 0;
}