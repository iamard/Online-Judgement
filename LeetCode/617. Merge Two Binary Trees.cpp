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
    void mergeTrees(TreeNode **root, TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr)
            *root = nullptr;
        else {
            *root = new TreeNode((t1? t1->val: 0) + (t2? t2->val: 0));
            mergeTrees(&((*root)->left), (t1? t1->left: nullptr), (t2? t2->left: nullptr));
            mergeTrees(&((*root)->right), (t1? t1->right: nullptr), (t2? t2->right: nullptr));
        }
    }

public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode *root;
        mergeTrees(&root, t1, t2);
        return root;
    }
};