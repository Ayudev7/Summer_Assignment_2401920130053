#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();

        
        if (m * n != r * c) {
            return mat;
        }

        vector<vector<int>> result(r, vector<int>(c));

        for (int i = 0; i < m * n; i++) {
            result[i / c][i % c] = mat[i / n][i % n];
        }

        return result;
    }
};

int main() {
    Solution sol;

    int m, n;
    cout << "Enter original matrix size (m x n): ";
    cin >> m >> n;

    vector<vector<int>> mat(m, vector<int>(n));
    cout << "Enter " << m * n << " elements row by row:" << endl;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    int r, c;
    cout << "Enter new shape (r x c): ";
    cin >> r >> c;

    vector<vector<int>> result = sol.matrixReshape(mat, r, c);

    if (result == mat && (m != r || n != c)) {
        cout << "Reshape not possible! Total elements must be equal." << endl;
    } else {
        cout << "Reshaped Matrix:" << endl;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << result[i][j];
                if (j < c - 1) cout << " ";
            }
            cout << endl;
        }
    }

    return 0;
}