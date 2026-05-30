class Solution {
    // Keep the bitmasks local to the class instance to avoid function stack overhead
    int cols = 0;
    int diag1 = 0;
    int diag2 = 0;

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        solve(0, n, board, ans);
        return ans;
    }

    void solve(int r, int n, vector<string> &board, vector<vector<string>> &ans) {
        if (r == n) {
            ans.push_back(board);
            return;
        }

        // Fast state check entirely within class registers
        int availablePositions = ((1 << n) - 1) & ~(cols | diag1 | diag2);

        while (availablePositions > 0) {
            int p = availablePositions & -availablePositions;
            availablePositions ^= p;
            int i = __builtin_ctz(p);

            // Save state copies before mutating global bitmasks
            int old_cols = cols;
            int old_d1 = diag1;
            int old_d2 = diag2;

            board[r][i] = 'Q';
            
            // Mutate masks directly
            cols |= p;
            diag1 = (diag1 | p) << 1;
            diag2 = (diag2 | p) >> 1;

            solve(r + 1, n, board, ans);

            // Backtrack: Restore previous state instantly
            board[r][i] = '.';
            cols = old_cols;
            diag1 = old_d1;
            diag2 = old_d2;
        }
    }
};