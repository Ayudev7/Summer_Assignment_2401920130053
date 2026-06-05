#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = INT_MAX;
        int maxprofit = 0;

        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < minprice) {
                minprice = prices[i]; // Buy at lowest price
            } else {
                int profit = prices[i] - minprice;
                maxprofit = max(maxprofit, profit);
            }
        }

        return maxprofit;
    }
};

int main() {
    Solution sol;

    int n;
    cout << "Enter number of days: ";
    cin >> n;

    vector<int> prices(n);
    cout << "Enter prices for each day: ";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    int result = sol.maxProfit(prices);

    if (result == 0) {
        cout << "No profit possible." << endl;
    } else {
        cout << "Maximum Profit: " << result << endl;
    }

    return 0;
}