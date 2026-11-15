class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;
    vector<int> used;

    void dfs(vector<int>& nums) 
    {
        if (cur.size() == nums.size()) 
        {
            ans.push_back(cur);
            return;
        }

        for (int i = 0; i < nums.size(); i++) 
        {
            if (used[i]) continue;

            used[i] = 1;
            cur.push_back(nums[i]);
            dfs(nums);
            cur.pop_back();
            used[i] = 0;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) 
    {
        used = vector<int>(nums.size(), 0);
        dfs(nums);
        return ans;
    }
};