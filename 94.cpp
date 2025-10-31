#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Solution class
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return res;

        // Traverse left subtree
        vector<int> left = inorderTraversal(root->left);
        res.insert(res.end(), left.begin(), left.end());

        // Visit current node
        res.push_back(root->val);

        // Traverse right subtree
        vector<int> right = inorderTraversal(root->right);
        res.insert(res.end(), right.begin(), right.end());

        return res;
    }
};

// Utility: build a sample tree and run traversal
int main() {
    /*
           1
            \
             2
            /
           3
    */

    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<int> inorder = sol.inorderTraversal(root);

    cout << "Inorder Traversal: ";
    for (int val : inorder)
        cout << val << " ";
    cout << endl;

    return 0;
}
