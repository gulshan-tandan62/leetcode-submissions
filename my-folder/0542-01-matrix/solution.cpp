class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<int,pair<int,int>>>q;
         vector<vector<int>>dis(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({0,{i,j}});
                    dis[i][j] = 0;
                }
            }
        }

    
        vector<pair<int,int>>dir = {{0,1},{1,0},{0,-1},{-1,0}};
        while(!q.empty())
        {
            int row = q.front().second.first;
            int col = q.front().second.second;
            int step = q.front().first;
            q.pop();
            
            for(int i=0;i<4;i++)
            {
                int nr = row+dir[i].first;
                int nc = col + dir[i].second;
                if(nr>=0 && nc>=0 && nr<n && nc<m && dis[nr][nc]==-1)
                {
                    dis[nr][nc] = step+1;
                    q.push({step+1,{nr,nc}});
                }
            }
        }
        return dis;
    }
};
