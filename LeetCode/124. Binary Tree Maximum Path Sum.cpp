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
    int maxPathSum(TreeNode *root, int &result) {
        if (root == nullptr) {
            return 0;
        } else {
            int left  = maxPathSum(root->left, result);
            left = left < 0? 0: left;
            
            int right = maxPathSum(root->right, result);
            right = right < 0? 0: right;
            
            int sum = left + right + root->val;
            if (sum > result)
                result = sum;
            
            return max(left, right) + root->val;
        }
    }
    
public:
    int maxPathSum(TreeNode* root) {
        int result = INT_MIN;
        maxPathSum(root, result);
        return result;
    }
};