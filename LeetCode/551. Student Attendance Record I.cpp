class Solution {
public:
    bool checkRecord(string s) {
        int absent = 0;
        int lstart = -1;
        int lend;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'L') {
                if (lstart == -1) {
                    lstart = i;
                    lend = i;
                } else {
                    lend = i;
                }
            } else {
                if (s[i] == 'A') {
                    absent ++;
                    if (absent > 1)
                        return false;
                }

                if (lstart != -1) {
                    int count = lend - lstart + 1;
                    if (count > 2)
                        return false;
                }
                
                lstart = -1;
            }
        }
        
        if (lstart != -1) {
            int count = lend - lstart + 1;
            if (count > 2)
                return false;
        }
        
        return true;
    }
};