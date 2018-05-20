/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
    TreeLinkNode* nextNode(TreeLinkNode *node) {
        while(node) {
            if (node->left)
                return node->left;
            else if (node->right)
                return node->right;
            node = node->next;
        }
        return nullptr;
    }
    
public:
    void connect(TreeLinkNode *root) {
        while(root) {
            TreeLinkNode *node = root;
            while(node) {
                if (node->left) {
                    if (node->right) {
                        node->left->next = node->right;
                    } else {
                        node->left->next = nextNode(node->next);
                    }
                }
                
                if (node->right) {
                    node->right->next = nextNode(node->next);
                }

                node = node->next;
            }
            
            root = nextNode(root);
        }
    }
};