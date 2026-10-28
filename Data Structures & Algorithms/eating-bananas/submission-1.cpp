#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
class Solution {
public:
    int minEatingSpeed(std::vector<int>& piles, int h) 
    {
        int l = 1;
        
        int r = *max_element(piles.begin(),piles.end());
        
        int ans = r;
        
        while (l <= r) 
        {
            int mid = l + (r - l) / 2;
            
            long long totalhours = 0;
            for (int pile : piles) 
            {
                totalhours += (pile + mid - 1) / mid;
            }
            
            if (totalhours <= h) 
            {
                ans = mid;       
                r = mid - 1;
            }
            
            else 
            {
                l = mid + 1;
            }
        }
        
        return ans;
    }
};
