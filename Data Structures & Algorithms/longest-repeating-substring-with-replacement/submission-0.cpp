#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        vector<int> freq(26, 0);
        int max_freq = 0;
        int max_len = 0;
        int l = 0;

        for (int r = 0; r < s.size(); r++) 
        {
            freq[s[r] - 'A']++;
            max_freq = max(max_freq, freq[s[r] - 'A']);

            while ((r - l + 1) - max_freq > k) 
            {
                freq[s[l] - 'A']--;
                l++;
            }

            max_len = max(max_len, r - l + 1);
        }

        return max_len;
    }
};