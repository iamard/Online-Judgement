class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for (int i = left; i <= right; i++) {
            int n = i; 
            while((n % 10) && ((i % (n % 10)) == 0)) {
                n = n / 10;
            }
            if (n == 0)
                result.push_back(i);
        }
        return result;
    }
};