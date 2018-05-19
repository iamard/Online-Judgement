class Solution {
public:
    bool isPalindrome(int x) {
        int val = x;
        int rev = 0;
        while(x > 0) {
            rev = rev * 10 + (x % 10);
            x /= 10;
        }
        return (val == rev);
    }
};