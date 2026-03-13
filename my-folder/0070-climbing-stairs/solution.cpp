class Solution {
    int dynamic(int n,vector<int>& dp)
    {
        if(n<0) return 0;
        if(n==0 || n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = dynamic(n-1,dp)+dynamic(n-2,dp);
    }
public:
    int climbStairs(int n) {
        if(n==1 || n==0) return n;
        vector<int>dp(n+1,-1);
        dynamic(n,dp);
        return dp[n];
    }
};
