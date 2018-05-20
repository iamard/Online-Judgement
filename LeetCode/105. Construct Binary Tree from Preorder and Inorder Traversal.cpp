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
    typedef vector<int>::iterator itor;

    TreeNode* buildTree(itor pbegin, itor pend, itor ibegin, itor iend) {
        if (pbegin == pend || ibegin == iend)
            return nullptr;

        TreeNode *root = new TreeNode(*pbegin);
        itor iroot = find(ibegin, iend, root->val);
        
        root->left  = buildTree(pbegin + 1, pbegin + (iroot - ibegin) + 1, ibegin, iroot); 
        root->right = buildTree(pbegin + (iroot - ibegin) + 1, pend, iroot + 1, iend);
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
};