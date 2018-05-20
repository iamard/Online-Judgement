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
    void pathSum(TreeNode *root, int sum, vector<int> &path, int curr, vector<vector<int>> &result) {
        if (root == nullptr)
            return;

        curr += root->val;
        path.push_back(root->val);
        
        if ((root->left == nullptr) &&
            (root->right == nullptr)) {
            if (curr == sum) {
                result.push_back(path);
            }
        } else {
            if (root->left) {
                pathSum(root->left, sum, path, curr, result);
            }
            
            if (root->right) {
                pathSum(root->right, sum, path, curr, result);
            }
        }
        
        path.pop_back();
    }
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        int curr = 0;
        vector<vector<int>> result;
        pathSum(root, sum, path, curr, result);
        return result;
    }
};