#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> ans;
    vector<int> subset;

    void helper(int i, vector<int>& nums) 
    {
        if (i == nums.size()) 
        {
            ans.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        helper(i + 1, nums);

        subset.pop_back();
        helper(i + 1, nums);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        helper(0, nums);
        return ans;
    }
};
