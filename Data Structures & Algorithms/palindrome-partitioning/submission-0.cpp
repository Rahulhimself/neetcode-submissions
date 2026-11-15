class Solution {
public:
    vector<vector<string>> ans;
    vector<string> cur;

    bool isPal(string& s, int l, int r) 
    {
        while (l < r) 
        {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    void dfs(int idx, string& s) 
    {
        if (idx == s.size()) 
        {
            ans.push_back(cur);
            return;
        }

        for (int i = idx; i < s.size(); i++) 
        {
            if (isPal(s, idx, i)) 
            {
                cur.push_back(s.substr(idx, i - idx + 1));
                dfs(i + 1, s);
                cur.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) 
    {
        dfs(0, s);
        return ans;
    }
};