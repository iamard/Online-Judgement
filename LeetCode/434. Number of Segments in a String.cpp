class Solution {
public:
    int countSegments(string s) {
        int start = 0;
        int result = 0;
        bool alpha = false;
        while(start < s.length()) {
            while(start < s.length() && s[start] == ' ') {
                start++;
            }
            
            alpha = false;
            while(start < s.length() && s[start] != ' ') {
                start++;
                alpha = true;
            }
            if (alpha)
                result++;
        }
        return result;
    }
};