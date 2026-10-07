/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool solve(TreeNode *root, int left, int right) {
        if (root == nullptr) {
            return true;
        }

        if (root->val <= left || root->val >= right) {
            return false;
        }

        bool isLeftValid = solve(root->left, left, root->val);
        bool isRightValid = solve(root->right, root->val, right);

        return isLeftValid && isRightValid;
    }

    bool isValidBST(TreeNode* root) {
        return solve(root, INT_MIN, INT_MAX);
    }
};
