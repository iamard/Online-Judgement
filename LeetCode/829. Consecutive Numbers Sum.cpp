class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int count = 1;
        for (long i = 1; (i * (i + 1)) < (2 * N); i++) {
            long remain = ((long)N - (i * (i + 1)) / 2) % (i + 1);
            if (remain == 0)
                count++;
        }        
        return count;
    }
};