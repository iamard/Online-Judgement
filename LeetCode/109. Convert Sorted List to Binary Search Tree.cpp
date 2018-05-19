/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* buildBalancedBST(vector<int> &value, int left, int right) {
        if (left > right)
            return nullptr;
        
        int middle = left + (right - left) / 2;
        TreeNode *root = new TreeNode(value[middle]);
        root->left  = buildBalancedBST(value, left, middle - 1);
        root->right = buildBalancedBST(value, middle + 1, right);
        return root;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> value;
        while(head) {
            value.push_back(head->val);
            head = head->next;
        }
        
        return buildBalancedBST(value, 0, value.size() - 1);
    }
};