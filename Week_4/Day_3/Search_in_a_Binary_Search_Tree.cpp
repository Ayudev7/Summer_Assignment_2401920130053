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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr || root->val == val) return root;

        if (val < root->val)
            return searchBST(root->left, val);
        else
            return searchBST(root->right, val);
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

void printLevelOrder(TreeNode* root) {
    if (root == nullptr) {
        cout << "[]" << endl;
        return;
    }

    queue<TreeNode*> q;
    q.push(root);
    cout << "[";
    bool first = true;

    while (!q.empty()) {
        TreeNode* curr = q.front(); q.pop();

        if (!first) cout << ", ";
        first = false;

        if (curr == nullptr) {
            cout << "null";
        } else {
            cout << curr->val;
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    cout << "]" << endl;
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

    int val;
    cout << "Enter value to search: ";
    cin >> val;

    TreeNode* root = insertLevelOrder(vals);

    TreeNode* result = sol.searchBST(root, val);

    cout << "Output: ";
    printLevelOrder(result);

    return 0;
}