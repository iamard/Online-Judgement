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
    int findTilt(TreeNode *root, int &tilt) {
        if (root == nullptr)
            return 0;

        int left  = findTilt(root->left, tilt);
        int right = findTilt(root->right, tilt); 
        
        tilt += abs(left - right);
        return root->val + left + right;
    }
    
public:
    int findTilt(TreeNode* root) {
        int tilt = 0;
        findTilt(root, tilt);
        return tilt;
    }
};