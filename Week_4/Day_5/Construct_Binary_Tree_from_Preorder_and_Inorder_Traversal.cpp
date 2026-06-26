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
    unordered_map<int, int> inorderIndex;
    int preorderIdx = 0;

    TreeNode* build(vector<int>& preorder, int inStart, int inEnd) {
        if (inStart > inEnd) return nullptr;

        int rootVal = preorder[preorderIdx++];
        TreeNode* root = new TreeNode(rootVal);

        int mid = inorderIndex[rootVal];

        root->left  = build(preorder, inStart, mid - 1);
        root->right = build(preorder, mid + 1, inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preorderIdx = 0;
        inorderIndex.clear();

        for (int i = 0; i < inorder.size(); i++)
            inorderIndex[inorder[i]] = i;

        return build(preorder, 0, inorder.size() - 1);
    }
};

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
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> preorder(n);
    cout << "Enter " << n << " preorder values: ";
    for (int i = 0; i < n; i++)
        cin >> preorder[i];

    vector<int> inorder(n);
    cout << "Enter " << n << " inorder values: ";
    for (int i = 0; i < n; i++)
        cin >> inorder[i];

    TreeNode* root = sol.buildTree(preorder, inorder);

    cout << "Output: ";
    printLevelOrder(root);

    return 0;
}