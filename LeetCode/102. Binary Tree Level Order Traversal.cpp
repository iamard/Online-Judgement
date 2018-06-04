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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr)
            return {};

        queue<TreeNode*> store;
        store.push(root);
        
        vector<vector<int>> result;
        vector<int> level;
        while(!store.empty()) {
            int count = store.size();
            
            level.clear();
            for (int i = 0; i < count; i++) {
                TreeNode *curr = store.front();
                store.pop();
                
                level.push_back(curr->val);
                
                if (curr->left) {
                    store.push(curr->left);
                }
                
                if (curr->right) {
                    store.push(curr->right);
                }
            }
            
            result.push_back(level);
        }
        return result;
    }
};