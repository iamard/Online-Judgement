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
    bool isSametree(TreeNode *s, TreeNode *t) {
        if (!s && !t)
            return true;
        else if (!s || !t)
            return false;
        else if (s->val != t->val)
            return false;
        else
            return isSametree(s->left, t->left) &&
                   isSametree(s->right, t->right);
    }
    
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (t == nullptr)
            return true;
        if (s == nullptr)
            return false;

        if (isSametree(s, t))
            return true;

        return isSubtree(s->left, t) ||
               isSubtree(s->right, t);
    }
};