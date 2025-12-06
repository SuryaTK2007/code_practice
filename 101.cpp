#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> L, R;
    int exp = -1e9;

    void left(TreeNode* root) {
        if (!root) { L.push_back(exp); return; }
        L.push_back(root->val);
        left(root->left);
        left(root->right);
    }

    void right(TreeNode* root) {
        if (!root) { R.push_back(exp); return; }
        R.push_back(root->val);
        right(root->right);
        right(root->left);
    }

    bool isSymmetric(TreeNode* root) {
        left(root->left);
        right(root->right);
        return L == R;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution s;
    if (s.isSymmetric(root)) 
        cout << "Symmetric\n";
    else 
        cout << "Not symmetric\n";

    return 0;
}
