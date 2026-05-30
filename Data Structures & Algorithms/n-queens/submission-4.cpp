class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        solve(0, n, 0, 0, 0, board, ans);
        return ans;
    }

    void solve(int r, int n, int cols, int diag1, int diag2, 
               vector<string> &board, vector<vector<string>> &ans) {
        if (r == n) {
            ans.push_back(board);
            return;
        }

        int availablePositions = ((1 << n) - 1) & ~(cols | diag1 | diag2);

        while (availablePositions > 0) {
            int p = availablePositions & -availablePositions; 
            int i = __builtin_ctz(p);
            availablePositions ^= p;

            board[r][i] = 'Q';
            
            solve(r + 1, n, cols | p, (diag1 | p) << 1, (diag2 | p) >> 1, board, ans);
            
            board[r][i] = '.'; 
        }
    }


};