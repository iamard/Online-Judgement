class Solution {
    bool traverse(vector<vector<int>> &graph, int curr, vector<int> &visited, vector<int> &result) {
        if (visited[curr] == 0) {
            visited[curr] = 1;
            for (int i = 0, count = graph[curr].size(); i < count; i++) {
                int next = graph[curr][i];
                if (visited[next] == 1) {
                    return true;
                } else {
                    bool cycle = traverse(graph, next, visited, result);
                    if (cycle)
                        return true;
                }
            }
            visited[curr] = 2;
            result.push_back(curr);
        }
        return false;
    }

public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> isRoot(numCourses, true);
        for (int i = 0; i < prerequisites.size(); i++) {
            graph[prerequisites[i].second].push_back(prerequisites[i].first);
            isRoot[prerequisites[i].first] = false;
        }

        queue<int> store;
        for (int i = 0; i < numCourses; i++) {
            if (isRoot[i]) {
                store.push(i);
            }
        }
        
        vector<int> visited(numCourses, 0);
        vector<int> result;
        while(!store.empty()) {
            int root = store.front();
            store.pop();a
            if (traverse(graph, root, visited, result)) {
                return {};
            }
        }

        if (result.size() != numCourses)
            return {};
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};
