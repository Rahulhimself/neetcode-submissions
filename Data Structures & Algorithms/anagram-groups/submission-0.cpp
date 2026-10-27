#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string, vector<string>> mp;

        for (string s : strs) 
        {
            string key(26, 0);
            for (char c : s) 
            {
                key[c - 'a']++;
            }
            
            mp[key].push_back(s);
        }

        vector<vector<string>> result;
        for (auto& pair : mp) 
        {
            result.push_back(pair.second);
        }

        return result;
    }
};