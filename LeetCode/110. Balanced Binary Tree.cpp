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
    int isBalanced(TreeNode *root, bool &result) {
        if (root == nullptr)
            return 0;
        
        if (result) {
            int left  = isBalanced(root->left, result);
            int right = isBalanced(root->right, result);
            
            if (abs(right - left) > 1)
                result = false;
        
            return max(left, right) + 1;
        } else {
            return -1;
        }
    }
    
public:
    bool isBalanced(TreeNode* root) {
        bool result = true;
        isBalanced(root, result);
        return result;
    }
};