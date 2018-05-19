/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    bool pruneTree(TreeNode *root, TreeNode *parent) {
        if (root == nullptr)
            return false;
        
        bool left = pruneTree(root->left, root);
        bool right = pruneTree(root->right, root);
        
        if (root->val == 0 && !left && !right) {
            if (parent && parent->left == root)
                parent->left = nullptr;
            else if (parent && parent->right == root)
                parent->right = nullptr;
            return false;
        } else {
            return (root->val == 1) || left || right;
        }
    }
    
public:
    TreeNode* pruneTree(TreeNode* root) {
        pruneTree(root, nullptr);
        return root;
    }
};