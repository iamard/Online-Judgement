class Solution {
public:
    bool judgeSquareSum(int c) {
        int left  = 0;
        int right = sqrt(c);
        while(left <= right) {
            int value = left * left + right * right;
            if (value == c) {
                return true;
            } else if (value > c) {
                right --;
            } else {
                left ++;
            }
        }
        return false;
    }
};