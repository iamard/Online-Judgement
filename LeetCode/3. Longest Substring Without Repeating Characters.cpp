class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int> table;
        
        int result = 0;
        int start  = -1;
        for (int i = 0; i < s.length(); i++) {
            if (table.find(s[i]) != table.end()) {
                start = max(start, table[s[i]]); 
            }
            table[s[i]] = i;
            result = max(result, i - start);
        }
        
        return result;
    }
};