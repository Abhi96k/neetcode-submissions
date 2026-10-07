
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    unordered_map<int, int> inorder_indices;
    
    TreeNode* solve(vector<int>& preorder, int prestart, int preend, vector<int>& inorder, int instart, int inend) {
        if (prestart > preend || instart > inend) {
            return nullptr;
        }

        TreeNode* node = new TreeNode(preorder[prestart]);
        
        int in_root = inorder_indices[node->val];
        int left_num = in_root - instart;

        node->left = solve(preorder, prestart + 1, prestart + left_num, inorder, instart, in_root - 1);
        node->right = solve(preorder, prestart + left_num + 1, preend, inorder, in_root + 1, inend);

        return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for (int i = 0; i < n; i++) {
            inorder_indices[inorder[i]] = i;
        }
        return solve(preorder, 0, n - 1, inorder, 0, n - 1);
    }
};
