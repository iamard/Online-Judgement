class Solution {
    double powCore(double x, long long n) {
        if (x == 1.0 || n == 0)
            return 1;
        else if (n == 1)
            return x;
        else {
            double result = powCore(x, n >> 1);
            result *= result;
            if (n & 1)
                result *= x;
            return result;
        }
    }

public:
    double myPow(double x, int n) {
        bool neg = false;
        long pow = n; 
        if (n < 0) {
            pow = -pow;
            neg = true;
        }
        
        double result = powCore(x, pow);
        return neg? 1.0 / result: result;
    }
};