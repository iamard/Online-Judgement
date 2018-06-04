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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> store;
        store.push(root);
        
        int result;
        while(!store.empty()) {
            for (int i = 0, count = store.size(); i < count; i++) {
                TreeNode *node = store.front();
                store.pop();

                if (i == 0) {
                    result = node->val;
                }
                
                if (node->left)
                    store.push(node->left);
                if (node->right)
                    store.push(node->right);
            }
        }
        return result;
    }
};