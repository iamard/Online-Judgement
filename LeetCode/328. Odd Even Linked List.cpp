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
    ListNode* oddEvenList(ListNode* head) {
        ListNode odd(0);
        ListNode even(0);
        
        int index = 1;
        ListNode *pOdd = &odd;
        ListNode *pEven = &even;
        while(head) {
            ListNode *node = head;
            head = head->next;

            if (index & 1) {
                pOdd->next = node;
                pOdd = pOdd->next;
            } else {
                pEven->next = node;
                pEven = pEven->next;
                pEven->next = nullptr;
            }
            index += 1;
        }

        pOdd->next = even.next;
        return odd.next;
    }
};