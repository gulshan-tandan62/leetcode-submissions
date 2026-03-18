class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int startColor = image[sr][sc];
        if(color == startColor) return image;
        image[sr][sc] = color;
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vis[sr][sc] = 1;
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            vector<pair<int,int>>directions = {{1,0},{0,1},{-1,0},{0,-1}};
            for(int i=0;i<4;i++)
            {
                int nr = row+directions[i].first;
                int nc = col + directions[i].second;
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && image[nr][nc]==startColor)
                {
                    image[nr][nc] = color;
                    vis[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
        }
        return image;
    }
};
