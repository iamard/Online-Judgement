class Solution {
public:
    int mySqrt(int x) {
        long left = 1;
        long right = x / 2 + 1;
        while(left <= right) {
            long mid = left + (right - left) / 2;
            long val = mid * mid;
            if (val == x) {
                return mid;
            } else if (val > x) {
                right = mid - 1;
            } else if (val < x) {
                left = mid + 1;
            }
        }
        return right;
    }
};