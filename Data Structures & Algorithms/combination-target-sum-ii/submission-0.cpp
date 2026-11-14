#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<vector<int>> ans;
    vector<int> current;

    void helper(int i, int target, vector<int>& candidates) 
    {
        
        if (target == 0) 
        {
            ans.push_back(current);
            return;
        }

        if (target < 0 || i == candidates.size()) 
        {
            return;
        }

        current.push_back(candidates[i]);
        helper(i + 1, target - candidates[i], candidates);

        current.pop_back();

        while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) 
        {
            i++;
        }

        helper(i + 1, target, candidates);
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(), candidates.end());
        helper(0, target, candidates);
        return ans;
    }
};
