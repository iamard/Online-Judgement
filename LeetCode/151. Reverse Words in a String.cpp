class Solution {
    void reverse(string &s, int left, int right) {
        while(left < right) {
            swap(s[left++], s[right--]);
        }
    }    

public:
    void reverseWords(string &s) {
        int curPos = 0;
        int left = 0;
        int right = 0;

        while(curPos < s.length()) {
            while(curPos < s.length() && s[curPos] == ' ') {
                curPos++;
            }

            if (curPos >= s.length())
                break;

            right = left;
            while(curPos < s.length() && s[curPos] != ' ') {
                s[right++] = s[curPos++];
            }
            if (right < s.length())
                s[right] = ' ';
            reverse(s, left, right - 1);
            left = right + 1;

            if (curPos < left)
                curPos = left;
        }
        s.resize(right);
        reverse(s, 0, s.length() - 1);
    }
};