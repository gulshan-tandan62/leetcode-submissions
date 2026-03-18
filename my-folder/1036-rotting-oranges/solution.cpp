class Solution {
 
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m =grid[0].size();
       // vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
       for(int i=0;i<n;i++)
       {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==2)
            {
                q.push({{i,j},0});
            }
        }
       }
       
    
      
        int time = 0;
        vector<pair<int,int>>directions = {{1,0},{0,1},{0,-1},{-1,0}};
        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int step = q.front().second;
            q.pop();
          
            time = max(time,step);
            for(int i=0;i<4;i++)
            {
                int nr = row + directions[i].first;
                int nc = col + directions[i].second;
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1)
                {
                    grid[nr][nc] = 2;
                    q.push({{nr,nc},step+1});
                }
                
            }

        }



        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return time;
    }
};
