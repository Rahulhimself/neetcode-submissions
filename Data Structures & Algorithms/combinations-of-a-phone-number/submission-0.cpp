class Solution {
public:
    vector<string> ans;
    string cur;
    vector<string> pad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void dfs(int idx, string& digits) 
    {
        if (idx == digits.size()) 
        {
            ans.push_back(cur);
            return;
        }

        for (char c : pad[digits[idx] - '0']) 
        {
            cur.push_back(c);
            dfs(idx + 1, digits);
            cur.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) 
    {
        if (digits.empty()) return {};
        dfs(0, digits);
        return ans;
    }
};