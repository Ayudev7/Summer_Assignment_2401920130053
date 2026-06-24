#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front(); q.pop();
                level.push_back(curr->val);

                if (curr->left)  q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

            result.push_back(level);
        }

        return result;
    }
};

TreeNode* insertLevelOrder(vector<int>& vals) {
    if (vals.empty() || vals[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(vals[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < vals.size()) {
        TreeNode* curr = q.front(); q.pop();

        if (i < vals.size() && vals[i] != -1) {
            curr->left = new TreeNode(vals[i]);
            q.push(curr->left);
        }
        i++;

        if (i < vals.size() && vals[i] != -1) {
            curr->right = new TreeNode(vals[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

int main() {
    Solution sol;

    int n;
    cout << "Enter number of nodes (use -1 for null): ";
    cin >> n;

    vector<int> vals(n);
    cout << "Enter " << n << " values (level order): ";
    for (int i = 0; i < n; i++)
        cin >> vals[i];

    TreeNode* root = insertLevelOrder(vals);

    vector<vector<int>> result = sol.levelOrder(root);

    cout << "Output: [";
    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if (j < result[i].size() - 1) cout << ", ";
        }
        cout << "]";
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}