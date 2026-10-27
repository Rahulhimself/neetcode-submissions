#include <string>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) 
    {
        if (s.length() < t.length()) return "";
        
        vector<int> counts(128, 0);
        for (char c : t) counts[c]++;
        
        int remaining = t.length();
        int min_len = INT_MAX;
        int start_idx = 0;
        int head = 0;
        
        for (int tail = 0; tail < s.length(); ++tail)
        {
            if (counts[s[tail]] > 0) 
            {
                remaining--;
            }
            counts[s[tail]]--;
            
            while (remaining == 0) 
            {
                if (tail - head + 1 < min_len) 
                {
                    min_len = tail - head + 1;
                    start_idx = head;
                }
                
                counts[s[head]]++;
                if (counts[s[head]] > 0) 
                {
                    remaining++;
                }
                head++;
            }
        }
        
        return min_len == INT_MAX ? "" : s.substr(start_idx, min_len);
    }
};
