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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)
            return nullptr;

        ListNode *prev = head;
        ListNode *curr = prev->next;
        while(curr) {
            while(curr && curr->val == prev->val) {
                ListNode *node = curr;
                curr = curr->next;
                delete node;
            }
            prev->next = curr;
            prev = prev->next;
            if (prev)
                curr = prev->next;
        }
        return head;
    }
};