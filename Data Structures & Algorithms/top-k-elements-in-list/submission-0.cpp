#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> mp;
        for (int x : nums) 
        {
            mp[x]++;
        }

        vector<vector<int>> buckets(nums.size() + 1);
        for (auto& [val, freq] : mp) 
        {
            buckets[freq].push_back(val);
        }

        vector<int> res;
        for (int i = buckets.size() - 1; i >= 0; --i) 
        {
            for (int val : buckets[i]) 
            {
                res.push_back(val);
                if (res.size() == k) return res;
            }
        }

        return res;
    }
};