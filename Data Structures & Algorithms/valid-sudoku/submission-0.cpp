class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] == '.') continue;

                // row check
                for(int c = 0; c < j; c++)
                {
                    if(board[i][c] == board[i][j]) return 0; 
                }
                for(int c = j+1; c < 9; c++)
                {
                    if(board[i][c] == board[i][j]) return 0; 
                }

                 // coloumn check
                for(int r = 0; r < i; r++)
                {
                    if(board[r][j] == board[i][j]) return 0; 
                }
                for(int r = i+1; r < 9; r++)
                {
                    if(board[r][j] == board[i][j]) return 0; 
                }

                // box check
                for(int r = i/3 * 3; r < i/3 * 3 + 3; r++)
                {
                    for(int c = j/3 * 3; c < j/3 * 3 + 3; c++)
                    {
                        if(r == i && c == j) continue;
                        if(board[r][c] == board[i][j]) return 0; 
                    }
                }
            }
        }
        return 1;
    }
};
