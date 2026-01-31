class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        int startColor = image[sr][sc];
        image[sr][sc] = color;
        vis[sr][sc] = 1;
        q.push({sr,sc});
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            vector<pair<int,int>>directions = {{0,1},{1,0},{-1,0},{0,-1}};
            for(int i=0;i<4;i++)
            {
                int nr  = r+directions[i].first;
                int nc = c+directions[i].second;
                if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc]==startColor && !vis[nr][nc])
                {
                    vis[nr][nc] = 1;
                    q.push({nr,nc});
                    image[nr][nc] = color;
                }
            }
        }
        return image;
    }
};
