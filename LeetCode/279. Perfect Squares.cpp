class Solution {    
public:
    int numSquares(int n) {
        int DP[n + 1];

        DP[0] = 0;
        DP[1] = 1;
        for (int i = 2; i <= n; i++) {
            DP[i] = i;
            for (int x = 1; (x * x) <= i; x++) {
                DP[i] = min(DP[i], 1 + DP[i - x * x]);
            }
        }
        return DP[n];
    }
};
