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
    int countNodes(TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        TreeNode *left = root->left;
        int lval = 1;
        while(left) {
            lval += 1;
            left = left->left;
        }
        
        TreeNode *right = root->right;
        int rval = 1;
        while(right) {
            rval += 1;
            right = right->right;
        }
        
        if (lval == rval) {
            return pow(2, rval) - 1;
        } else {
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};