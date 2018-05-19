class Solution {
    void permuteUnique(vector<int> &nums, int pos, vector<bool> &visited, 
            vector<int> &value, vector<vector<int>> &result) {
        if (pos == nums.size()) {
            result.push_back(value);
        } else {
            for (int i = 0; i < nums.size(); i++) {
                if (visited[i] == false) {
                    if (i > 0 && (nums[i] == nums[i - 1]) && visited[i - 1] == false)
                        continue;
                    
                    visited[i] = true;
                    value.push_back(nums[i]);
                    permuteUnique(nums, pos + 1, visited, value, result);
                    value.pop_back();
                    visited[i] = false;
                }
            }
        }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> value;
        vector<vector<int>> result;
        vector<bool> visited(nums.size(), false);
        
        sort(nums.begin(), nums.end());

        permuteUnique(nums, 0, visited, value, result);
        return result;
    }
};