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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return true;
        
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = nullptr;
        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }
        
        prev->next = nullptr;
        
        // Reverse right part
        prev = nullptr;
        while(slow) {
            ListNode *next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        
        while(prev && head) {
            if (prev->val != head->val)
                return false;
            prev = prev->next;
            head = head->next;
        }
        return true;
    }
};