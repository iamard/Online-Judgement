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
    void buildList(TreeNode *root) {
        if (root == nullptr)
            return;

        buildList(root->left);
        buildList(root->right);

        if (root->left) {
            TreeNode *tail = root->left;
            while(tail->right) {
                tail = tail->right;
            }
            tail->right = root->right;
            root->right = root->left;
            root->left  = nullptr;
        }
    }

public:
    void flatten(TreeNode* root) {
        buildList(root);
    }
};