class Solution {
    void generateValidString(string &V, stack<char> &S) {
        for (int i = 0; i < V.length(); i++) {
            if (V[i] != '#') {
                S.push(V[i]);
            } else {
                if (!S.empty()) {
                    S.pop();
                }
            }
        }
    }
    
public:
    bool backspaceCompare(string S, string T) {
        stack<char> s1;
        stack<char> s2;
        generateValidString(S, s1);
        generateValidString(T, s2);
        if (s1.size() != s2.size()) {
            return false;
        }
        
        while(!s1.empty()) {
            if (s1.top() != s2.top())
                return false;
            s1.pop();
            s2.pop();
        }
        return true;
    }
};