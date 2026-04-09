class Solution {

    int solve(int i, int j, vector<vector<int>>& grid,vector<vector<int>>& dp) {
        int n = grid.size();
        int m = grid[0].size();
        if (i >= n || j >= m)
            return INT_MAX;
        if(i==n-1 && j==m-1) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int down = solve(i+1,j,grid,dp);
        int right = solve(i,j+1,grid,dp);
       return dp[i][j] = grid[i][j] + min(down,right);
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(0, 0, grid,dp);
    }
};
