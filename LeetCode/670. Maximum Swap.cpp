class Solution {
public:
    int maximumSwap(int num) {
        string orgVal = to_string(num);
        string maxVal = orgVal;
        sort(maxVal.begin(), maxVal.end(), greater<char>());

        int left = 0;
        int right = maxVal.length() - 1;
        while(left < right) {
            while(left < right && orgVal[left] == maxVal[left]) {
                left++;
            }
            
            while(left < right && maxVal[left] != orgVal[right]) {
                right--;
            }
            
            if (left != right) {
                swap(orgVal[left], orgVal[right]);
                break;
            }
        }
        return stoi(orgVal);
    }
};