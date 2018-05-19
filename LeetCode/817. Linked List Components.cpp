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
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_map<int, int> table;
        for (int i = 0; i < G.size(); i++) {
            table[G[i]] = G[i];
        }

        ListNode *prev = nullptr;
        int merged = 0;
        while(head) {
            prev = head;
            head = head->next;
            if (prev && head) {
                if (table.find(prev->val) != table.end() &&
                    table.find(head->val) != table.end()) {
                    merged++;
                }
            }
        }
        
        return G.size() - merged;
    }
};