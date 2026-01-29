class Solution {

    int solve(vector<int>& coins ,int amount,vector<int>& dp)
    {
        if(amount==0) return 0;
        if(amount<0) return INT_MAX;

        if(dp[amount]!=-1) return dp[amount];
        int ans = INT_MAX;
        for(auto coin : coins)
        {
            int res = solve(coins,amount-coin,dp);
            if(res!=INT_MAX)
            {
                ans = min(ans,1+res);
            }
        } 
       return dp[amount]  = ans;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-1);
        int res = solve(coins,amount,dp);
        return res==INT_MAX?-1:res;
    }
};
