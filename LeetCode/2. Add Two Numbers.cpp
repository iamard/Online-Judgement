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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr || l2 == nullptr)
            return nullptr;

        ListNode dummy = ListNode(0);
        ListNode *pCur = &dummy;

        int c = 0;
        while(l1 || l2) {
            int v1 = (l1)? l1->val: 0;
            int v2 = (l2)? l2->val: 0;
            
            int v = v1 + v2 + c;
            if (v >= 10) {
                c = 1;
                v -= 10;
            } else {
                c = 0;
            }

            pCur->next = new ListNode(v);
            pCur = pCur->next;
            
            l1 = l1? l1->next: nullptr;
            l2 = l2? l2->next: nullptr;
        }
        
        if (c) {
            pCur->next = new ListNode(c);
        }

        return dummy.next;
    }
};