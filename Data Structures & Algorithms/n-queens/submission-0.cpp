class Solution {
public:


    vector<vector<string>> ans;
    vector<string> board;
    vector<int> col, diag1, diag2;

    void dfs(int r, int n) 
    {
        if (r == n) 
        {
            ans.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) 
        {
            if (col[c] || diag1[r - c + n - 1] || diag2[r + c]) continue;

            board[r][c] = 'Q';
            col[c] = diag1[r - c + n - 1] = diag2[r + c] = 1;

            dfs(r + 1, n);

            board[r][c] = '.';
            col[c] = diag1[r - c + n - 1] = diag2[r + c] = 0;
        }
    }

    vector<vector<string>> solveNQueens(int n) 
    {
        board = vector<string>(n, string(n, '.'));
        col = vector<int>(n, 0);
        diag1 = vector<int>(2 * n, 0);
        diag2 = vector<int>(2 * n, 0);

        dfs(0, n);
        return ans;
    }
};