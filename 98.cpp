#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }

private:
    bool helper(TreeNode* root, long minVal, long maxVal) {
        if (root == nullptr) 
            return true;

        if (root->val <= minVal || root->val >= maxVal) 
            return false;

        return helper(root->left, minVal, root->val) &&
               helper(root->right, root->val, maxVal);
    }
};

int main() {
    /*
        Constructing this BST:

                10
               /  \
              5    15
                    \
                     20
    */

    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->right->right = new TreeNode(20);

    Solution obj;

    if (obj.isValidBST(root))
        cout << "Tree is a VALID BST" << endl;
    else
        cout << "Tree is NOT a BST" << endl;

    return 0;
}
