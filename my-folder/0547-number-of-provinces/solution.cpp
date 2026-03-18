class Solution {
    void bfs(int i,vector<int>& vis,vector<vector<int>>& adjlst)
    {
        queue<int>q;
        q.push(i);
        vis[i] = 1;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto neighbor : adjlst[node])
            {
                if(!vis[neighbor]){
                    vis[neighbor] = 1;
                    q.push(neighbor);
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V =  isConnected.size();
        vector<vector<int>>adjlst(V);
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(i!=j && isConnected[i][j]==1)
                {
                    adjlst[i].push_back(j);
                    adjlst[j].push_back(i);
                }
            }
        }
        vector<int>vis(V,0);
        int count= 0 ;
        for(int i=0;i<V;i++)
        {
            if(!vis[i]){
                count++;
                bfs(i,vis,adjlst);
            }
        }
        return count;
    }
};
