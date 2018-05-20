class Solution {
    int countBinarySubstrings(string &s, int left, int right) {
        int count = 1;
        left--;
        right++;
        while((left >= 0) && 
              (right < s.length()) && 
              (s[left] == s[left + 1]) && 
              (s[right] == s[right - 1])) {
            count++;
            left--;
            right++;
        }
        return count;
    }

public:
    int countBinarySubstrings(string s) {
        int count = 0;
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == '0' && s[i + 1] == '1') {
                count += countBinarySubstrings(s, i, i + 1);
            } else if (s[i] == '1' && s[i + 1] == '0') {
                count += countBinarySubstrings(s, i, i + 1);
            }
        }
        return count;
    }
};