class Solution {
public:
    string addStrings(string num1, string num2) {
        int pos1 = num1.length() - 1;
        int pos2 = num2.length() - 1;
        
        string result;
        int carry = 0;
        while(pos1 >= 0 || pos2 >= 0) {
            int value1 = (pos1 >= 0)? num1[pos1--] - '0': 0;
            int value2 = (pos2 >= 0)? num2[pos2--] - '0': 0;
            int sumVal = value1 + value2 + carry;
            
            if (sumVal >= 10) {
                carry = sumVal / 10;
                sumVal -= 10;
            } else {
                carry = 0;
            }
            
            result += (sumVal + '0');
        }
        
        if (carry)
            result += (carry + '0');
        
        reverse(result.begin(), result.end());
        return result;
    }
};