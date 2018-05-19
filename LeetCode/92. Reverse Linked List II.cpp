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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *org = head;
        
        int count = 1;
        ListNode *prev = nullptr;
        while(count < m && head) {
            prev = head;
            head = head->next;
            count++;
        }
        
        ListNode *node = nullptr;
        ListNode *tail = head;
        while(count <= n && head) {
            ListNode *curr = head;
            head = head->next;
            
            curr->next = node;
            node = curr;
            count++;
        }
        
        if (prev)
            prev->next = node;

        if (tail)
            tail->next = head;

        return (m != 1)? org: node;
    }
};