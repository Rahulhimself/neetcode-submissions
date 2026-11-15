class Solution {
public:
    int m, n;

    bool dfs(int r, int c, int idx, vector<vector<char>>& board, string& word) 
    {
        if (idx == word.size()) return true;
        
        if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != word[idx]) return false;

        char temp = board[r][c];
        board[r][c] = '#'; // mark visited

        bool found = dfs(r + 1, c, idx + 1, board, word) ||
                     dfs(r - 1, c, idx + 1, board, word) ||
                     dfs(r, c + 1, idx + 1, board, word) ||
                     dfs(r, c - 1, idx + 1, board, word);

        board[r][c] = temp; // backtrack
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) 
    {
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (dfs(i, j, 0, board, word)) return true;
            }
        }
        return false;
    }
};