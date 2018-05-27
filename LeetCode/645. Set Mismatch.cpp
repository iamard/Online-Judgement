class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int pos = 1;
        int dup;
        int sum = nums[0];
        while(pos < nums.size()) {
            if (nums[pos - 1] == nums[pos]) {
                dup = nums[pos];
            }
            sum += nums[pos];
            pos += 1;
        }
        
        int other = (1 + nums.size()) * nums.size() / 2 - (sum - dup);
        return { dup, other };        
    }
};