class Solution {
    bool traverse(vector<vector<int>> &graph, int curr, vector<int> &visited) {
        visited[curr] = 1;
        for (int i = 0; i < graph[curr].size(); i++) {
            int next = graph[curr][i];
            if (visited[next] == 1) {
                return false;
            } else if (visited[next] == 0) {
                bool status = traverse(graph, next, visited);
                if (status == false)
                    return false;
            }
        }
        visited[curr] = 2;
        return true;
    }

public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        for (int i = 0; i < prerequisites.size(); i++) {
            graph[prerequisites[i].second].push_back(prerequisites[i].first);
        }

        vector<int> visited(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                bool status = traverse(graph, i, visited);
                if (status == false)
                    return false;
            }
        }
        return true;
    }
};