class Solution {
    bool dfs(int i,int j,int k,vector<vector<char>>& board, string word)
    {
        int n = board.size();
        int m = board[0].size();
        if(k==word.size()) return true;
        if(i<0||j<0||i>=n|| j>=m|| board[i][j]!=word[k]) return false;

        char curr = board[i][j];
        board[i][j] = ' ';
        bool ans = false;
        ans = ans || dfs(i+1,j,k+1,board,word);
        ans = ans || dfs(i,j+1,k+1,board,word);
        ans = ans || dfs(i-1,j,k+1,board,word);
        ans = ans || dfs(i,j-1,k+1,board,word);

        board[i][j] = curr;
        return ans;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j] == word[0]){
                    if(dfs(i,j,0,board,word)) return true;
                }
            }
        }
        return false;
    }
};
