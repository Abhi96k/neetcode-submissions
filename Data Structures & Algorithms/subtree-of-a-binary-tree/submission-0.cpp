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
    bool issameTree(TreeNode *root1, TreeNode *root2){
        if (root1 == nullptr && root2 == nullptr) {
            return true; 
        }
        if (root1 == nullptr || root2 == nullptr) {
            return false;
        }
        if (root1->val != root2->val) {
            return false; 
        }

        bool left = issameTree(root1->left, root2->left); 
        bool right = issameTree(root1->right, root2->right);
        return left && right; 
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (subRoot == nullptr) {
            return true; 
        }

        if (root == nullptr) {
            return false; 
        }

        if (issameTree(root, subRoot)) {
            return true; 
        }

        bool left = isSubtree(root->left, subRoot);
        bool right = isSubtree(root->right, subRoot);

        return left || right; 
    }
};
