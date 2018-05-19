/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int count = 0;
        ListNode *node = root;
        while(node) {
            count++;
            node = node->next;
        }
        
        int batch  = count / k;
        int remain = count % k;
        
        vector<ListNode*> result;
        while(root) {
            result.push_back(root);

            count = batch;
            if (remain) {
                count++;
                remain--;
            }
            
            int skip = 1;
            while (skip < count) {
                skip++;
                root = root->next;
            }
            
            ListNode *next = root->next;
            root->next = nullptr;
            root = next;
        }

        while(result.size() < k) {
            result.push_back({});
        }
        
        return result;
    }
};