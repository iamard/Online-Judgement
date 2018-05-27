class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> store;

        store.insert(n);
        while(n != 1) {
            int s = 0;
            while(n != 0) {
                int v = (n % 10);
                s += v * v;
                n /= 10;
            }
            if (store.find(s) != store.end())
                return false;
            store.insert(s);
            n = s;
        }
        return true;
    }
};