/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    void insertNode(ListNode *prev, ListNode *head, ListNode *node) {
        while(head) {
            if (head->val >= node->val) {
                break;
            }
            prev = head;
            head = head->next;
        }

        node->next = head;
        prev->next = node;
    }

public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        
        ListNode dummy(0);
        ListNode *curr;
        dummy.next = head;
        curr = head->next;
        head->next = nullptr;

        while(curr) {
            ListNode *node = curr;
            curr = curr->next;
            
            insertNode(&dummy, dummy.next, node);
        }
        
        return dummy.next;
    }
};