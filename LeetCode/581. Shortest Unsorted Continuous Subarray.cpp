/*
 * O(n) algorithm found from the following URL:
 * http://www.cnblogs.com/grandyang/p/6876457.html
 */
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int count = nums.size();
        int minVal = nums[count - 1];
        int maxVal = nums[0];

        int left = 1;
        int right = 0;
        for (int i = 1; i < count; i ++) {
            minVal = min(minVal, nums[count - i - 1]);
            maxVal = max(maxVal, nums[i]);

            if (minVal < nums[count - i - 1])
                left = count - i - 1;
            if (maxVal > nums[i])
                right = i;
        }
        return right - left + 1;
    }
};