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

class Codec {
public:
    string serialize(TreeNode* root) {
        if (root == nullptr) return "#";

        string left  = serialize(root->left);
        string right = serialize(root->right);

        return to_string(root->val) + "," + left + "," + right;
    }

    TreeNode* deserialize(string data) {
        queue<string> tokens;
        stringstream ss(data);
        string token;

        while (getline(ss, token, ','))
            tokens.push(token);

        return buildTree(tokens);
    }

    TreeNode* buildTree(queue<string>& tokens) {
        string val = tokens.front(); tokens.pop();

        if (val == "#") return nullptr;

        TreeNode* root = new TreeNode(stoi(val));
        root->left  = buildTree(tokens);
        root->right = buildTree(tokens);

        return root;
    }
};

TreeNode* insertLevelOrder(vector<int>& vals) {
    if (vals.empty() || vals[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(vals[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() &&