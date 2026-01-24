class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adjlst(n);
        for(auto it : prerequisites)
        {
            adjlst[it[1]].push_back(it[0]);
        }
        vector<int>inDegree(n,0);
        for(int i=0;i<n;i++)
        {
            for(auto it : adjlst[i])
            {
                inDegree[it]++;
            }

        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(inDegree[i]==0)q.push(i);
        }
        vector<int>res;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(auto neighbor : adjlst[node])
            {
                inDegree[neighbor]--;
                if(inDegree[neighbor]==0)
                {
                    q.push(neighbor);
                }
            }
        }
        return res.size()==n;
    }
};
