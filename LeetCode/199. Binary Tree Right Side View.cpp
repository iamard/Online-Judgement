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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr)
            return {};
        
        vector<int> result;
        
        queue<TreeNode*> store;
        store.push(root);
        while(!store.empty()) {
            result.push_back(store.front()->val);
            
            int count = store.size();
            for (int i = 0; i < count; i++) {
                TreeNode *node = store.front();
                store.pop();

                if (node->right)
                    store.push(node->right);
                if (node->left)
                    store.push(node->left);
            }
        }
        
        return result;
    }
};