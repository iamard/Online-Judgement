class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> table;
        for (int i = 0; i < strs.size(); i++) {
            string key = strs[i];
            sort(key.begin(), key.end());
            table[key].push_back(strs[i]);
        }

        vector<vector<string>> result;
        for (auto &itor: table) {
            vector<string> temp(itor.second.begin(), itor.second.end());
            result.push_back(temp);
        }
        return result;
    }
};