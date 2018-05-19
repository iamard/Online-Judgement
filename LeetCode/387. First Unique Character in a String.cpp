class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int, pair<int, int>> table;
        for (int i = 0; i < s.length(); i++) {
            if (table.find(s[i]) == table.end())
                table[s[i]] = make_pair(i, 1);
            else
                table[s[i]].second++;
        }
        
        int result = INT_MAX;
        for (auto &itor: table) {
            if (itor.second.second == 1) {
                result = min(result, itor.second.first);
            }
        }
        
        return (result == INT_MAX)? -1: result;
    }
};