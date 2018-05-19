class Solution {
    void reverseVowels(string &s, int left, int right) {
        string vowels = "AEIOUaeiou";
        
        while(left < right) {
            while(left < right && vowels.find(s[left]) == string::npos) {
                left++;
            }
            
            while(left < right && vowels.find(s[right]) == string::npos) {
                right--;
            }
            swap(s[left++], s[right--]);
        }
    }

public:
    string reverseVowels(string s) {
        int left  = 0;
        int right = s.length() - 1;
        reverseVowels(s, left, right);
        return s;
    }
};