class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (n <= 1)
            return { 0 };
        
        vector<unordered_set<int>> graph(n);
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i].first].insert(edges[i].second);
            graph[edges[i].second].insert(edges[i].first);
        }

        queue<int> store;
        for (int i = 0; i < graph.size(); i++) {
            if (graph[i].size() == 1) {
                store.push(i);
            }
        }

        int vertex = graph.size();
        while(vertex > 2) {
            int batch = store.size();
            vertex -= batch;
         
            for (int i = 0; i < batch; i++) {
                int node = store.front();
                store.pop();
                for (int next: graph[node]) {
                    graph[next].erase(node);
                    if (graph[next].size() == 1)
                        store.push(next);
                }
            }
        }

        vector<int> result;
        while(!store.empty()) {
            result.push_back(store.front());
            store.pop();
        }
        
        return result;
    }
};