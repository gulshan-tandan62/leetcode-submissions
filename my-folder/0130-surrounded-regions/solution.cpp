class Solution {
    void bfs(int i,int j,int n,int m,vector<vector<int>>& vis,vector<vector<char>>& board)
    {
        queue<pair<int,int>>q;
        q.push({i,j});
        vis[i][j] = 1;
        vector<pair<int,int>>directions = {{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nr = row+directions[i].first;
                int nc = col + directions[i].second;
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && board[nr][nc]=='O'){
                    vis[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O') bfs(i,0,n,m,vis,board);
            if(board[i][m-1]=='O') bfs(i,m-1,n,m,vis,board);
        }
        for(int j=0;j<m;j++)
        {
            if(board[0][j]=='O') bfs(0,j,n,m,vis,board);
            if(board[n-1][j]=='O') bfs(n-1,j,n,m,vis,board);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==0 && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
