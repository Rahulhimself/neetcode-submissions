#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> ans;
    vector<int> current;

    void helper(int i, int target, vector<int>& nums) 
    {
        if (target == 0) 
        {
            ans.push_back(current);
            return;
        }

        if (target < 0 || i == nums.size()) 
        {
            return;
        }

        current.push_back(nums[i]);
        helper(i, target - nums[i], nums);

        current.pop_back();
        helper(i + 1, target, nums);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) 
    {
        helper(0, target, nums);
        return ans;
    }
};
