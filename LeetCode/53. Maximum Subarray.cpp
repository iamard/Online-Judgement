class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sumVal = nums[0];
        int result = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            sumVal = max(nums[i], sumVal + nums[i]);
            result = max(result, sumVal);
        }
        return result;
    }
};