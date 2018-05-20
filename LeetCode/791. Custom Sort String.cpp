class Solution {
public:
    string customSortString(string S, string T) {
        vector<int> dict(26, INT_MAX);
        for (int i = 0; i < S.length(); i++) {
            dict[S[i] - 'a'] = i;
        }

        sort(T.begin(), T.end(), [&dict](const char c1, const char c2) {
            return dict[c1 - 'a'] < dict[c2 - 'a'];
        });
            
        return T;
    }
};