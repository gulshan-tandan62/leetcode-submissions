class Solution {
   void island(int r, int c,vector<vector<int>>& vis,vector<vector<char>>& grid)
    {
        queue<pair<int,int>> q;
        q.push({r,c});
        vis[r][c] = 1;
        vector<vector<int>>directions = {{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nr  = row + directions[i][0];
                int nc = col + directions[i][1];
                if(nr>=0 && nc>=0 && nr<grid.size()&& nc<grid[0].size() && !vis[nr][nc] && grid[nr][nc]=='1')
                {
                    vis[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int count= 0;
        int n =grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m ;j++)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                {
                    island(i,j,vis,grid);
                    count++;
                }
            }

        }
        return count;

    }
};
