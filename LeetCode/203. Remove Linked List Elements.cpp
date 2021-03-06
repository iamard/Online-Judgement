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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode *prev = &dummy;
        while(head) {
            if (head->val == val) {
                prev->next = head->next;
                head->next = nullptr;
                delete head;
                head = prev->next;
            } else {
                prev = head;
                head = head->next;
            }
        }
        
        return dummy.next;
    }
};