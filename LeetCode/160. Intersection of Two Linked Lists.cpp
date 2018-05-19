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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr)
            return nullptr;
        
        ListNode *node = headA;
        while(node->next) {
            node = node->next;
        }

        ListNode *tail = node;
        
        // Create cycle
        node->next = headA;
        
        ListNode *slow = headB;
        ListNode *fast = headB;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }
        
        if (fast == nullptr || fast->next == nullptr) {
            tail->next = nullptr;
            return nullptr;
        }
        
        node = headB;
        while(node != fast) {
            node = node->next;
            fast = fast->next;
        }
        
        tail->next = nullptr;
        return node;
    }
};