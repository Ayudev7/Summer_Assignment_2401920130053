#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;

        while (left < right) {
            int h = min(height[left], height[right]);
            int w = right - left;
            int area = h * w;

            maxWater = max(maxWater, area);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxWater;
    }
};

int main() {
    Solution sol;

    int n;
    cout << "Enter number of lines: ";
    cin >> n;

    vector<int> height(n);
    cout << "Enter " << n << " heights: ";
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    int result = sol.maxArea(height);

    cout << "Maximum Water Container: " << result << endl;

    return 0;
}