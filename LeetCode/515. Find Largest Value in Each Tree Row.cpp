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
    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr)
            return {};
        
        queue<TreeNode*> store;
        store.push(root);
        
        vector<int> result;
        while(!store.empty()) {
            int maxVal = INT_MIN;
            for (int i = 0, count = store.size(); i < count; i++) {
                TreeNode* node = store.front();
                store.pop();
                
                maxVal = max(maxVal, node->val);
                
                if (node->left)
                    store.push(node->left);
                if (node->right)
                    store.push(node->right);
            }
            result.push_back(maxVal);
        }
        return result;
    }
};