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
    
    TreeNode* buildTree(itor ibegin, itor iend, itor pbegin, itor pend) {
        if (ibegin == iend || pbegin == pend)
            return nullptr;

        TreeNode *root = new TreeNode(*(pend - 1));
        itor iroot = find(ibegin, iend, root->val);
        
        root->left  = buildTree(ibegin, iroot, pbegin, pbegin + (iroot - ibegin));
        root->right = buildTree(iroot + 1, iend, pbegin + (iroot - ibegin), pend - 1);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }
};