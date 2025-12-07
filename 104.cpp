#include <bits/stdc++.h>
using namespace std;
// height of binary tree=depth of binary tree-1
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

int main() {
    /*
         Sample Tree
               1
              / \
             2   3
            / 
           4
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    Solution obj;
    cout << "Max Depth = " << obj.maxDepth(root) << endl;

    return 0;
}
