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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode *pCurr = &dummy;
        while(l1 && l2) {
            if (l1->val <= l2->val) {
                pCurr->next = l1;
                l1 = l1->next;
            } else {
                pCurr->next = l2;
                l2 = l2->next;
            }
            pCurr = pCurr->next;
        }

        if (l1)
            pCurr->next = l1;

        if (l2)
            pCurr->next = l2;

        return dummy.next;
    }
};