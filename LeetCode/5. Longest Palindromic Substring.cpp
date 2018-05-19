class Solution {
public:
    string longestPalindrome(string s) {
        int L = s.length();

        int DP[L][L] = { false };
        for (int i = 0; i < L; i++) {
            DP[i][i] = true;
        }
        
        string result = s.substr(0, 1);
        for (int l = 2; l <= L; l++) {
            for (int i = 0; i < L - l + 1; i++) {
                int j = i + l - 1;
                if (s[i] == s[j]) {
                    if (l == 2) {
                        DP[i][j] = true;
                        result = s.substr(i, 2);
                    } else if (DP[i + 1][j - 1] == true) {
                        DP[i][j] = true;
                        result = s.substr(i, l);
                    }
                }
            }
        }
        return result;
    }
};