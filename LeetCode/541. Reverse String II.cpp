class Solution {
    void reverse(string &s, int left, int right) {
        while(left < right) {
            swap(s[left++], s[right--]);
        }
    }
    
public:
    string reverseStr(string s, int k) {
        int start = 0;
        while(start < s.length()) {
            int left  = start;
            int right = start + k - 1;
            if (right >= s.length())
                right = s.length() - 1;
            reverse(s, left, right);
            
            start += 2 * k;
        }
        return s;
    }
};