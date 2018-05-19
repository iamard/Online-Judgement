class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> table;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            int remain = target - nums[i];
            if (table.find(remain) != table.end()) {
                result.push_back(table[remain]);
                result.push_back(i);
                break;
            } else {
                table[nums[i]] = i;
            }
        }
        return result;
    }
};
