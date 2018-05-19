class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> prod(num1.length() + num2.length(), 0);
        for (int i = num1.length() - 1; i >= 0; i--) {
            for (int j = num2.length() - 1; j >= 0; j--) {
                int value1 = num1[i] - '0';
                int value2 = num2[j] - '0';
                prod[i + j + 1] += (value1 * value2);
            }
        }
        
        int carry = 0;
        string result;
        for (int i = prod.size() - 1; i >= 0; i--) {
            int value = prod[i] + carry;
            if (value >= 10) {
                carry = value / 10;
                value = value % 10;
            } else {
                carry = 0;
            }
            prod[i] = value;
            
            result = to_string(prod[i]) + result;
        }

        if (carry)
            result = to_string(carry) + result;

        size_t pos = result.find_first_not_of('0');
        if (pos == string::npos) {
            return "0";
        }
    
        return result.substr(pos);
    }
};