#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += mat[i][i];           
            sum += mat[i][n - 1 - i];  
        }

        
        if (n % 2 != 0) {
            sum -= mat[n / 2][n / 2];
        }

        return sum;
    }
};

int main() {
    Solution sol;

    int n;
    cout << "Enter matrix size : ";
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));
    cout << "Enter " << n * n << " elements row by row:" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    int result = sol.diagonalSum(mat);
    cout << "Diagonal Sum: " << result << endl;

    return 0;
}