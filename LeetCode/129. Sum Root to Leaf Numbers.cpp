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
    void sumNumbers(TreeNode *root, vector<int> &path, int &sum) {
        if (root == nullptr)
            return;

        path.push_back(root->val);
        if (root->left == nullptr &&
            root->right == nullptr) {
            int value = 0;
            for (int i = 0; i < path.size(); i++) {
                value = value * 10 + path[i];
            }
            sum += value;
        } else {
            if (root->left)
                sumNumbers(root->left, path, sum);
            if (root->right)
                sumNumbers(root->right, path, sum);
        }
        path.pop_back();
    }
    
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        vector<int> path;
        sumNumbers(root, path, sum);
        return sum;
    }
};