class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int val1 = nums[size - 1] * nums[size - 2] * nums[size - 3];
        int val2 = nums[size - 1] * nums[1] * nums[0];
        return max(val1, val2);
    }
};