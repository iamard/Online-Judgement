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
    void traverse(TreeNode *root, vector<int> &value, vector<string> &result) {
        if (root->left == nullptr && root->right == nullptr) {
            string path;
            for (int i = 0; i < value.size(); i++) {
                path += to_string(value[i]);
                path += "->";
            }
            path += to_string(root->val);
            result.push_back(path);
        } else {
            value.push_back(root->val);
            if (root->left)
                traverse(root->left, value, result);
            if (root->right)
                traverse(root->right, value, result);
            value.pop_back();
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr)
            return { };

        vector<string> result;
        vector<int> value;
        traverse(root, value, result);
        return result;
    }
};