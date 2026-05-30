class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        // Pass masks cleanly by value. The compiler maximizes register usage here.
        solve(0, n, 0, 0, 0, board, ans);
        return ans;
    }

    void solve(int r, int n, int cols, int diag1, int diag2, 
               vector<string> &board, vector<vector<string>> &ans) {
        if (r == n) {
            ans.push_back(board);
            return;
        }

        // Identify available spots
        int availablePositions = ((1 << n) - 1) & ~(cols | diag1 | diag2);

        while (availablePositions > 0) {
            int p = availablePositions & -mask_lowest(availablePositions); 
            int i = __builtin_ctz(p);
            availablePositions ^= p;

            board[r][i] = 'Q';
            
            // Shift inline during the function call. 
            // This allows the CPU to calculate the next state simultaneously using instruction pipelining.
            solve(r + 1, n, cols | p, (diag1 | p) << 1, (diag2 | p) >> 1, board, ans);
            
            board[r][i] = '.'; // Backtrack
        }
    }

private:
    inline int mask_lowest(int x) {
        return x;
    }
};