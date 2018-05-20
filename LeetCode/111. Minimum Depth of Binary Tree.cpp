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
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int left = minDepth(root->left);
        if (root->right == nullptr)
            return left + 1;
        
        int right = minDepth(root->right);
        if (root->left == nullptr)
            return right + 1;

        return min(left, right) + 1;
    }
};