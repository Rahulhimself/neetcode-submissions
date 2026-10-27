#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string encode(vector<string>& strs) 
    {
        string res = "";
        for (const string& s : strs) 
        {
            res += to_string(s.size()) + "#" + s;
        }
        return res;
    }

    vector<string> decode(string s) 
    {
        vector<string> res;
        int i = 0;

        while (i < s.size()) 
        {
            int at = s.find('#', i);
            int len = stoi(s.substr(i, at - i));
            res.push_back(s.substr(at + 1, len));
            i = at + 1 + len;
        }

        return res;
    }
};