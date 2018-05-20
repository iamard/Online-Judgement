/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
    UndirectedGraphNode* DFSTraversal(UndirectedGraphNode *curr, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> &store) {
        UndirectedGraphNode *node = new UndirectedGraphNode(curr->label);
        store[curr] = node;

        int count = curr->neighbors.size();
        for (int i = 0; i < count; i++) {
            UndirectedGraphNode *next = curr->neighbors[i];
            if (store.find(next) == store.end()) {
                DFSTraversal(next, store);
            }
            node->neighbors.push_back(store[next]);
        }

        return node;
    }

public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == nullptr)
            return nullptr;
        
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> store;
        
        DFSTraversal(node, store);
        return store[node];
    }
};