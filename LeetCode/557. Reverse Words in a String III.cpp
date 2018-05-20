class Solution {
public:
    string reverseWords(string s) {
        int pos = 0;
        while(pos < s.length()) {
            while(pos < s.length() && s[pos] == ' ') {
                pos++;
            }
            
            int left  = pos;
            int right = pos;
            while(right < s.length() && s[right] != ' ') {
                right++;
            }
            
            reverse(s.begin() + left, s.begin() + right);
            pos = right;
        }
        return s;
    }
};