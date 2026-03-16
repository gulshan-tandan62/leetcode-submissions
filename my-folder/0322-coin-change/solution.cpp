class Solution {
    int solve(int amount,vector<int>& coins,vector<int>& dp)
    {
        if(amount==0) return 0;
        if(amount<0){
            return INT_MAX;
        }
        if(dp[amount]!=-1){
            return dp[amount];
        }
        int mini = INT_MAX;
        for(auto coin : coins)
        {
            int res = solve(amount-coin ,coins,dp);
            if(res!=INT_MAX)
            {
                mini = min(mini,res+1);
            }
        }
        return dp[amount] = mini;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-1);
        int ans = solve(amount,coins,dp);
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};
