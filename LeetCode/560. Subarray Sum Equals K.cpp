class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> table;
        
        int sum   = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum == k)
                count++;
            
            if (table.find(sum - k) != table.end()) {
                count += table[sum - k];
            }
            
            table[sum]++;
        }
        
        return count;
    }
};