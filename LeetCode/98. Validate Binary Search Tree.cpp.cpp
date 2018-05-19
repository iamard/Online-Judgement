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
    bool isValidBST(TreeNode *root, TreeNode *minNode, TreeNode *maxNode) {
        if (root == nullptr)
            return true;
        else {
            if ((minNode && (root->val <= minNode->val)) ||
                (maxNode && (root->val >= maxNode->val)))
                return false;
            
            return isValidBST(root->left, minNode, root) &&
                   isValidBST(root->right, root, maxNode);
        }
    }

public:
    bool isValidBST(TreeNode* root) {
        if (root == nullptr)
            return true;
        
        return isValidBST(root, nullptr, nullptr);
    }
};