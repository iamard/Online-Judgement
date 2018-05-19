class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length())
            return false;

        unordered_map<int, int> s2t;
        unordered_map<int, int> t2s;
        for (int i = 0; i < s.length(); i++) {
            if (s2t.find(s[i]) == s2t.end()) {
                s2t[s[i]] = t[i];
            } else if (s2t[s[i]] != t[i]) {
                return false;
            }

            if (t2s.find(t[i]) == t2s.end()) {
                t2s[t[i]] = s[i];
            } else if (t2s[t[i]] != s[i]) {
                return false;
            }
        }
        
        return true;
    }
};