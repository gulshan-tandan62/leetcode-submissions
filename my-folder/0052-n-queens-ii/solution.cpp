class Solution {
    int count = 0;
    bool isSafe(int i,int j,int n,vector<string>& board)
    {
        for(int k= j-1;k>=0;k--)
        {
            if(board[i][k]=='Q') return false;

        }
        for(int k=i-1,l=j-1;k>=0 && l>=0;k--,l--)
        {
            if(board[k][l]=='Q') return false;

        }
         for(int k=i+1,l=j-1;k<n && l>=0;k++,l--)
        {
            if(board[k][l]=='Q') return false;

        }
        return true;

    }
    void placeQueens(int col,int n,vector<string>& board)
    {
        if(col==n){
            count++;return;
        }

        for(int i=0;i<n;i++)
        {
            if(isSafe(i,col,n,board))
            {
                board[i][col]  = 'Q';
                placeQueens(col+1,n,board);
                board[i][col] = '.';
            }
        }
    }
public:
    int totalNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        placeQueens(0,n,board);
        return count;
    }
};
