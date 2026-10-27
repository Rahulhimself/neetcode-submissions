#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_map<char, int> last_idx;
        int max_len = 0;
        int l = 0;

        for (int r = 0; r < s.size(); r++) 
        {
            char c = s[r];

            if (last_idx.find(c) != last_idx.end() && last_idx[c] >= l) 
            {
                l = last_idx[c] + 1;
            }

            last_idx[c] = r;
            max_len = max(max_len, r - l + 1);
        }

        return max_len;
    }
};