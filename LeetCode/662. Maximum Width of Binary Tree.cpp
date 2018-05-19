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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        queue<pair<TreeNode*, int>> store;
 
        store.push(make_pair(root, 0));
        
        int result = 1;
        while(!store.empty()) {            
            int count = store.size();
            int minVal = INT_MAX;
            int maxVal = INT_MIN;
            for (int i = 0; i < count; i++) {
                TreeNode *node = store.front().first;
                int offset = store.front().second;
                store.pop();
                
                minVal = min(minVal, offset);
                maxVal = max(maxVal, offset);
                
                if (node->left)
                    store.push(make_pair(node->left, 2 * offset + 0));
                if (node->right)
                    store.push(make_pair(node->right, 2 * offset + 1));
            }
            result = max(result, maxVal - minVal + 1);
        }

        return result;
    }
};