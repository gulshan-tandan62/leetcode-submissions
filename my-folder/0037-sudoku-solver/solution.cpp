class Solution {
    bool isSafe(int i,int j,char num,vector<vector<char>>& board)
    {
        
        for(int k=0;k<9;k++)
        {
            if(board[i][k]==num || board[k][j]==num) return false;
        }
       int startRow = (i/3)*3;
       int startCol  = (j/3)*3;
       for(int row = 0;row<3;row++)
       {
        for(int col = 0;col<3;col++)
        {
            if(board[startRow+row][startCol+col]==num) return false;
        }
       }
       return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.'){
                    for(char num='1';num<='9';num++)
                    {
                        if(isSafe(i,j,num,board)){
                            board[i][j] = num;
                            if(solve(board)) return true;
                            board[i][j] = '.';
                            
                        }
                    }
                    return false;
                }

            }
        }
        return true;

    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
