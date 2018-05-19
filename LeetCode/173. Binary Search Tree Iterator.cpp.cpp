/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    stack<TreeNode*> pool;
    
public:
    BSTIterator(TreeNode *root) {
        if (root == nullptr)
            return;

        while(root) {
            pool.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !pool.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *node = pool.top();
        pool.pop();
        
        int result = node->val;
        if (node->right) {
            node = node->right;
            while(node) {
                pool.push(node);
                node = node->left;
            }
        }
        return result;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */