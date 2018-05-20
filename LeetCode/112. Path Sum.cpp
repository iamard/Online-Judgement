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
    bool hasPathSum(TreeNode *root, int sum, int &curr) {
        if (root == nullptr)
            return false;
        
        if (root->left == nullptr &&
            root->right == nullptr) {
            return ((curr + root->val) == sum);
        } else {
            curr += root->val;
            
            bool status = false;
            if (root->left) {
                status = hasPathSum(root->left, sum, curr);
                if (status)
                    return true;
            }

            if (root->right) {
                status = hasPathSum(root->right, sum, curr);
                if (status)
                    return true;
            }
            
            curr -= root->val;
            return false;
        }
    }
    
public:
    bool hasPathSum(TreeNode* root, int sum) {
        int curr = 0;
        return hasPathSum(root, sum, curr);
    }
};