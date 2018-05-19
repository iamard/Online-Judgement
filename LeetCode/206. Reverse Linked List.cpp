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
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        while(head) {
            ListNode *node = head;
            head = head->next;
            
            node->next = prev;
            prev = node;
        }
        
        return prev;
    }
};