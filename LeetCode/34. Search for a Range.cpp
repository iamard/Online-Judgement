class Solution {
    int lowerBound(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
                if (nums[left] == target) {
                    return left;
                }
            } else {
                right = mid;
            }
        }
        return nums[left] == target? left: -1;
    }

    int upperBound(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size();
        while(left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left - 1;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return { -1, -1 };

        int lower = lowerBound(nums, target);
        if (lower == -1)
            return { -1, -1 };
        
        int upper = upperBound(nums, target);
        return { lower, upper };
    }
};
