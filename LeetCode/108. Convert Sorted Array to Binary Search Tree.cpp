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
    TreeNode* buildBalancedBST(vector<int> &nums, int left, int right) {
        if (left > right) {
            return nullptr;
        } else {
            int middle = left + (right - left) / 2;
            TreeNode *root = new TreeNode(nums[middle]);
            root->left  = buildBalancedBST(nums, left, middle - 1);
            root->right = buildBalancedBST(nums, middle + 1, right);
            return root;
        }
    }
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBalancedBST(nums, 0, nums.size() - 1);
    }
};