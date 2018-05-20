class Solution {
    void DFSTraversal(unordered_map<string, multiset<string>> &table, string curr, vector<string> &result) {
        while(!table[curr].empty()) {
            string next = *table[curr].begin();
            table[curr].erase(table[curr].begin());
            DFSTraversal(table, next, result);
        }
        result.push_back(curr);
    }
    
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, multiset<string>> table;
        for (int i = 0; i < tickets.size(); i++) {
            table[tickets[i].first].insert(tickets[i].second);
        }
        
        vector<string> result;
        DFSTraversal(table, "JFK", result);
        reverse(result.begin(), result.end());

        return result;
    }
};