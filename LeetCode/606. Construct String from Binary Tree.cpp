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
    void traverse(TreeNode *t, string &o) {
        o += to_string(t->val);
        if (t->left == nullptr && t->right == nullptr)
            return;
        
        if (t->left || t->right) {
            o += "(";
            if (t->left) {
                traverse(t->left, o);
            }
            o += ")";
        }
            
        if (t->right) {
            o += "(";
            traverse(t->right, o);
            o += ")";
        }
    }
    
public:
    string tree2str(TreeNode* t) {
        if (t == nullptr)
            return "";

        string o;
        traverse(t, o);
        return o;
    }
};