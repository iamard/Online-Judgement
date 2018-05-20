class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        
        int right = s.length() - 1;
        while(right > 0 && s[right - 1] >= s[right]) {
            right --;
        }

        if (right == 0)
            return -1;

        int left = right;
        while(left < s.length() && s[left] > s[right - 1]) {
            left++;
        }
        
        swap(s[right - 1], s[left - 1]);
        sort(s.begin() + right, s.end());
        return stol(s) > INT_MAX? -1: stol(s);
    }
};