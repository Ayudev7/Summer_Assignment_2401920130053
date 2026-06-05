#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution{
    public:
    vector<int> twosum(vector<int> &nums,int target){
        unordered_map<int, int> M;
        for(int i=0;i<=nums.size();i++){
            int complement =target - nums[i];
            if(M.count(complement)){
                return {M[complement],i};

            }
            M[nums[i]]=i;
        }
        return {};
    }

};
int main(){
    Solution sol;
    int n, target;
    cout << "Enter the number of element";
    cin >> n;

    vector<int> nums(n);
    cout << "enter the " << n << " element";
    for(int i= 0;i<nums.size();i++){
        cin >> nums[i];
    }
    cout << "enter thr target";
    cin >> target;

    vector<int> result = sol.twosum(nums,target);

    if(result.empty()){
        cout << "result not found";
    }
    cout << "output :["<< result[0] << ","<< result[1] <<"]"; 




}