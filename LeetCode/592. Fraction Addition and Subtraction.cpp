class Solution {
    int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    
public:
    string fractionAddition(string expression) {
        vector<int> numerator;
        vector<int> denominator;

        int sign = 1;
        int left = 0;
        while(left < expression.length()) {
            if (expression[left] == '-' ||
                expression[left] == '+') {
                sign = (expression[left] == '-')? -1: 1;
                left++;
            }

            int num = 0;
            while(left < expression.length() && expression[left] >= '0' && expression[left] <= '9') {
                num = num * 10 + (expression[left] - '0');
                left++;
            }
            numerator.push_back(sign * num);
            
            left++;
            
            int den = 0;
            while(left < expression.length() && expression[left] >= '0' && expression[left] <= '9') {
                den = den * 10 + (expression[left] - '0');
                left++;
            }
            denominator.push_back(den);
        }
        
        int lcm = denominator[0];
        for (int i = 1; i < denominator.size(); i++) {
            lcm = (lcm * denominator[i]) / gcd(lcm, denominator[i]);
        }

        int den = 0;
        for (int i = 0; i < numerator.size(); i++) {
            den += numerator[i] * (lcm / denominator[i]);
        }
        
        sign = (den < 0)? -1: 1;
        den  = abs(den);
      
        int scale = gcd(den, lcm);
        return to_string(sign * den / scale) + "/" + to_string(lcm / scale);
    }
};