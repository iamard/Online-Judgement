class Solution {
public:
    int longestMountain(vector<int>& A) {
        int pos = 1;
        int len = 0;
        while(pos < A.size()) {
            while(pos < A.size() && A[pos - 1] == A[pos])
                pos++;
            
            int inc = 0;
            while(pos < A.size() && A[pos - 1] < A[pos]) {
                inc++;
                pos++;
            }

            int dec = 0;
            while(pos < A.size() && A[pos - 1] > A[pos]) {
                dec++;
                pos++;
            }

            if (inc && dec) {
                len = max(len, inc + dec + 1);
            }
        }
        
        return len;
    }
};
