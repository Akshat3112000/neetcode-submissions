class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        
        // Start recursion with 0 masks for cols, diag1, and diag2
        solve(0, n, 0, 0, 0, board, ans);
        return ans;
    }

    void solve(int r, int n, int cols, int diag1, int diag2, 
               vector<string> &board, vector<vector<string>> &ans) {
        if (r == n) {
            ans.push_back(board);
            return;
        }

        // Get a mask of all available positions in this row
        // (cols | diag1 | diag2) gives 1s where queens attack. 
        // We invert it (~) and limit it to the first 'n' bits.
        int availablePositions = ((1 << n) - 1) & ~(cols | diag1 | diag2);

        while (availablePositions > 0) {
            // Extract the lowest set bit (position to place the queen)
            int p = availablePositions & -availablePositions;
            availablePositions ^= p; // Clear this position from available options

            int i = __builtin_ctz(p); // Find the column index (0-indexed)

            board[r][i] = 'Q';
            
            // Recurse to next row:
            // Shift diag1 left and diag2 right to account for diagonal steps
            solve(r + 1, n, cols | p, (diag1 | p) << 1, (diag2 | p) >> 1, board, ans);
            
            board[r][i] = '.'; // Backtrack
        }
    }
};