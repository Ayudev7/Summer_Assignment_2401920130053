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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;
        if (p->val != q->val) return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
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
    cout << "Enter number of nodes for tree p (use -1 for null): ";
    cin >> n;
    vector<int> vals1(n);
    cout << "Enter " << n << " values (level order): ";
    for (int i = 0; i < n; i++) cin >> vals1[i];

    int m;
    cout << "Enter number of nodes for tree q (use -1 for null): ";
    cin >> m;
    vector<int> vals2(m);
    cout << "Enter " << m << " values (level order): ";
    for (int i = 0; i < m; i++) cin >> vals2[i];

    TreeNode* p = insertLevelOrder(vals1);
    TreeNode* q = insertLevelOrder(vals2);

    bool result = sol.isSameTree(p, q);

    if (result)
        cout << "Output: true (Same Tree)" << endl;
    else
        cout << "Output: false (Different Trees)" << endl;

    return 0;
}