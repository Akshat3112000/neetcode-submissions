class Solution {
    int row[8] = {0};
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        vector<vector<string>> ans;
        solve(n,0,board,ans);
        return ans;
    }

    void solve(int n,int r,vector<string> &board, vector<vector<string>> &ans)
    {
        if(r == n)
        {
            ans.push_back(board);
            return;
        }
       for(int i = 0; i < n; i++)
       {
            board[r][i] = 'Q';
            row[r] |= 1 << i; //set

            if(valid(r))
            {
                solve(n,r+1,board,ans);
            }
            board[r][i] = '.';
            row[r] ^= 1 << i; //unset
       } 
    }
    bool valid(int r)
    {
        int mask = 0;
        for(int i = r - 1; i >= 0; i--)
        {
            mask |= row[i];
            mask |= row[i] << (r - i);
            mask |= row[i] >> (r - i);
        }
        return ((mask & row[r]) == 0);
    }

};
