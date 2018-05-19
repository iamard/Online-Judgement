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
    int traverse(TreeNode *root, int &diameter) {
        if (root == nullptr)
            return 0;
        int left  = traverse(root->left, diameter);
        int right = traverse(root->right, diameter);
        diameter = max(diameter, left + right);
        return max(left, right) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        traverse(root, diameter);
        return diameter;
    }
};