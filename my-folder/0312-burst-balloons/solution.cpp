class Solution {
    int solve(int i,int j,vector<int>& nums,vector<vector<int>>& dp)
    {
        if(i+1==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = 0;
        for(int k=i+1;k<j;k++)
        {
            int coin = nums[i]* nums[k] * nums[j];
            
            coin += solve(i,k,nums,dp);
            coin += solve(k,j,nums,dp);

            ans = max(coin,ans);
        }
        return dp[i][j] = ans;
    }
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(0,nums.size()-1,nums,dp);
    }
};
