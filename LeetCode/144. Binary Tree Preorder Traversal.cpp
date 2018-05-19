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
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr)
            return {};
        
        vector<int> result;
        
        stack<TreeNode*> store;
        store.push(root);
        while(!store.empty()) {
            TreeNode *node = store.top();
            store.pop();
            
            result.push_back(node->val);
            if (node->right)
                store.push(node->right);
            if (node->left)
                store.push(node->left);
        }
        
        return result;
    }
};