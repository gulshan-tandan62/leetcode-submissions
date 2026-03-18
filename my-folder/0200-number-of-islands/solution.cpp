class Solution {
    void bfs(int i,int j,int n,int m,vector<vector<int>>& vis,vector<vector<char>>& grid)
    {
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j] = 1;
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            vector<pair<int,int>>directions = {{0,1},{1,0},{-1,0},{0,-1}};
            for(int l=0;l<4;l++)
            {
                int nr = row + directions[l].first;
                int nc = col + directions[l].second;
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]=='1')
                {
                    vis[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int count = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]=='1')
               { count++;
                bfs(i,j,n,m,vis,grid);}
            }
        }
        return count;
    }
};
