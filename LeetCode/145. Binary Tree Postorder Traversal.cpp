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
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr)
            return {};
        
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(root);
        while(!s1.empty()) {
            TreeNode *node = s1.top();
            s1.pop();

            s2.push(node);
            if (node->left)
                s1.push(node->left);
            if (node->right)
                s1.push(node->right);
        }

        vector<int> result;
        while(!s2.empty()) {
            TreeNode *node = s2.top();
            s2.pop();
            result.push_back(node->val);
        }
        return result;
    }
};