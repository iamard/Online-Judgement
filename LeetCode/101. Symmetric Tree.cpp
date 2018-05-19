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
    bool isSymmetric(TreeNode *s1, TreeNode *s2) {
        if (s1 == nullptr && s2 == nullptr)
            return true;
        else if (s1 == nullptr || s2 == nullptr)
            return false;
        else if (s1->val != s2->val)
            return false;
        else
            return isSymmetric(s1->left, s2->right) &&
                   isSymmetric(s1->right, s2->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        return isSymmetric(root->left, root->right);
    }
};