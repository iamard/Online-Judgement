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
    void constructMaximumBinaryTree(TreeNode *root, unordered_map<int, int> &table, int value) {
        if (table[root->val] < table[value]) {
            if (root->right) {
                constructMaximumBinaryTree(root->right, table, value);
            } else {
                root->right = new TreeNode(value);
            }
        } else if (table[root->val] > table[value]) {
            if (root->left) {
                constructMaximumBinaryTree(root->left, table, value);
            } else {
                root->left = new TreeNode(value);
            }
        }
    }

public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() <= 0)
            return nullptr;
        
        unordered_map<int, int> table;
        priority_queue<int> queue;
        for (int i = 0; i < nums.size(); i++) {
            table[nums[i]] = i;
            queue.push(nums[i]);
        }

        TreeNode *root = new TreeNode(queue.top());
        queue.pop();

        while(!queue.empty()) {
            int value = queue.top();
            queue.pop();
            constructMaximumBinaryTree(root, table, value);
        }
        
        return root;
    }
};