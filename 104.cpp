#include <bits/stdc++.h>
using namespace std;

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
    int helper(TreeNode* root){
        if (root == nullptr) return 0;

        int l = 1 + helper(root->left);
        int r = 1 + helper(root->right);

        return max(l, r);
    }

    int maxDepth(TreeNode* root) {
        return helper(root);
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
