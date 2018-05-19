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
        ListNode dummy(0);
        dummy.next = head;

        ListNode *prev = &dummy;
        while(head) {
            ListNode *tail = head->next;
            while(tail && head->val == tail->val) {
                ListNode *node = tail;
                tail = tail->next;
                delete node;
            }
            
            if (tail != head->next) {
                delete head;
                prev->next = tail;
                head = tail;
            } else {
                prev = prev->next;
                head = head->next;
            }
        }
        
        return dummy.next;
    }
};